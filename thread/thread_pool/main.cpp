#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<functional>
#include<atomic>
#include<vector>
using namespace std;


class ThreadPool{
private:

    // 工作线程执行任务的函数
    void worker(); 

    // 存储线程池中的线程
    vector<thread> threads;
    // 任务队列
    queue<function<void()>> tasks;
    // 保护任务队列的互斥锁
    mutex queue_mutex;
    // 条件变量，用于线程同步
    condition_variable condition;
    // 停止标志
    atomic<bool> stopFlag;


public:
    ThreadPool(size_t thread_num): stopFlag(false){
        for(size_t i = 0; i < thread_num; ++i){
            threads.emplace_back(&ThreadPool::worker, this); // 相当于threads.emplace_back([this](){this->worker();});
        }                                                   // 等价于 std::thread t(&ThreadPool::worker, this);
    }                                                       // threads.emplace_back(std::move(t));

    // 析构函数，等待所有任务完成
    ~ThreadPool(){
        stopFlag.store(true);
        condition.notify_all(); // 唤醒所有等待的线程
        for(auto& thread: threads){
            if(thread.joinable()){
                thread.join();
            }
        }
    }
    
    // 向线程池中添加任务
    template <typename F, typename... Args> // F 是模板参数，表示传递给模板的第一个类型（通常是函数对象或可调用对象的类型）。Args... 是模板参数包，用来表示零个或多个额外的模板类型参数。
    void enqueue(F&& f, Args&&... args) {
        {
            // 将任务放入队列时需要加锁
            std::lock_guard<std::mutex> lock(queue_mutex);
            tasks.push(std::bind(std::forward<F>(f), std::forward<Args>(args)...)); // std::bind 绑定了函数 f 和其参数 args...，将它们组合成一个单一的可调用对象。
        }
        // 通知一个空闲线程
        condition.notify_one();
    };

    void stop(){
        stopFlag.store(true);
        condition.notify_all();
        for (auto& thread : threads){
            if(thread.joinable()){
                thread.join();
            }
        }
    }
    
};

void ThreadPool::worker(){
    while(true){
        function<void()> task; // 定义一个函数对象，用于存储从任务队列中取出的任务
        {
            // 代码块保证了锁的生命周期，防止task()执行的时候，还依然持有锁
            // 等待任务队列中有任务
            unique_lock<mutex> lock(queue_mutex);
            condition.wait(lock, [this]{return !tasks.empty() || stopFlag.load();});
            if (stopFlag.load() && tasks.empty())
            {
                return;
            }
            task = std::move(tasks.front()); // std::move 本身位于 std 命名空间中，所以即使你写了 using namespace std;，你仍然需要在使用 std::move 时显式写出 std:: 前缀。
            tasks.pop();
        }
        // 执行任务
        task();
    }
}

mutex mtx; // 全局互斥锁
int main(){
    ThreadPool pool(4);
    for(int i = 0; i < 10; ++i){
        pool.enqueue([i]{
            mtx.lock();
            cout << "Task " << i << " is running."
            << this_thread::get_id() << endl;
            this_thread::sleep_for(chrono::seconds(1));
            mtx.unlock();
        });
    }

    this_thread::sleep_for(chrono::seconds(3));

    pool.stop();

    return 0;
}