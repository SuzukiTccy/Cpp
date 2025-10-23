#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<functional>
#include<atomic>
#include<chrono>
using namespace std;

mutex mtx; // 全局锁，用于打印


class ThreadPool{
private:
    void worker();
    vector<thread> threadspool;
    queue<function<void()>> tasks_queue;
    mutex queue_mtx;
    condition_variable tasks_available;
    atomic<bool> stop{false};

public:
    ThreadPool(size_t threads){
        for(size_t i = 0; i < threads; ++i){
            threadspool.emplace_back(&ThreadPool::worker,this); // emplace_back()方法和push_back()是不一样的
                                                                // emplace_back()方法是可以接受参数
                                                                // 然后用这个参数来构造一个对象，直接放到vector末尾
                                                                // 如果和push_back()方法一样用也可以，但会多一个拷贝构造的过程
                                                                // 就损失了emplace_back()方法的优势
        }
    }

    ~ThreadPool(){
        stop.store(true);
        tasks_available.notify_all();
        for(thread& thread : threadspool){
            thread.join();
        }
    }
    
    void add_task(function<void()> task){
        // 在移动前检查任务是否有效
        if (!task) {
            // task 是空的，可能是构造失败或已经被移动
            cerr << "警告: 尝试添加空任务到队列" << endl;
            return;  // 直接返回，不添加到队列
        }

        {
            unique_lock<mutex> lock(queue_mtx);
            tasks_queue.emplace(std::move(task)); // 和tasks_queue.emplace(task)的区别
        }                                         // 将 task 的所有权转移到队列中，而不是拷贝一份
                                                  // 调用后，原对象 task 不再可用
        tasks_available.notify_one();
    }

    void stopwork(){
        stop.store(true);
        tasks_available.notify_all();
    }
        
};

void ThreadPool::worker(){
    function<void()> task;
    while(true){
        unique_lock<mutex> lock(queue_mtx);
        tasks_available.wait(lock, [this](){
            return !tasks_queue.empty() || stop.load();
        }); // wait()方法会一直阻塞，直到被notify_one()或者notify_all()唤醒

        if(stop.load() && tasks_queue.empty()) return; // 如果stop为true，并且任务队列为空，则退出循环
        
        task = std::move(tasks_queue.front());
        tasks_queue.pop();
        lock.unlock(); // unique_lock可以手动解锁

        task();
    }
}

void work_function(){
    for(int i = 0;i < 20; ++i){
        mtx.lock();
        cout << "thread id: " << this_thread::get_id() << " i: " << i << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    mtx.lock();
    cout << "thread id: " << this_thread::get_id() << " finished" << endl;
    mtx.unlock();
}



void threadspool_example(){
    ThreadPool pool(8);
    for(int i = 0;i < 20; ++i){
        pool.add_task(work_function);
        mtx.lock();
        cout << "Task_id: " << i << " is ready!" << endl;
        mtx.unlock();
    }
    this_thread::sleep_for(chrono::seconds(6));

    pool.stopwork();
}


