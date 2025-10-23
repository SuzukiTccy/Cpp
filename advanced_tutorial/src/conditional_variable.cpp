#include<iostream>
#include<vector>
#include<queue>
#include<thread>
#include<mutex>
#include<chrono>
#include<random>
#include<condition_variable> // C++11 standard condition_variable library
using namespace std;


class ThreadSafeBuffer{
    private:
        queue<int> buffer;
        const size_t capacity = 10; // 缓冲区大小
        mutex mtx;
        condition_variable not_full; // 缓冲区未满条件
        condition_variable not_empty; // 缓冲区非空条件
        bool stop = false; // 停止标志
    
    public:

        // get_buffer_capacity: 获取缓冲区容量
        size_t get_buffer_capacity() const{
            return capacity;
        }

        // 生产者: 添加数据，如果缓冲区满则等待
        void produce(int item){
            unique_lock<mutex> lock(mtx);
            not_full.wait(lock, [this](){ 
                return buffer.size() < capacity || stop; 
            }); // 没有达成条件时，会释放锁，并进入等待状态，直到被通知

            if(stop) return;

            buffer.push(item);
            cout << "生产: " << item << " 缓冲区大小: " << buffer.size() << endl;

            // 通知消费者线程
            not_empty.notify_one();
        }

        // 消费者: 消费数据，如果缓冲区空则等待
        int consume(){
            unique_lock<mutex> lock(mtx);
            not_empty.wait(lock, [this](){
                return buffer.size() > 0 || stop;
            });
            
            if (stop && buffer.empty()) return -1; // 
            
            int item = buffer.front();
            buffer.pop();
            cout << "消费: " << item << " 缓冲区大小: " << buffer.size() << endl;

            not_full.notify_one();

            return item;
        }

        // 通知所有等待线程，停止生产和消费
        void stop_producing(){
            {
                unique_lock<mutex> lock(mtx);
                stop = true;
            }
            not_full.notify_all();
            not_empty.notify_all();
        }
};


// 模拟生产者的不同生产速度
void fast_producer(ThreadSafeBuffer& buffer, int id){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 150);

    int item = 0;
    for(int i = 0; i < 10; ++i){
        item = id * 100 + i;
        buffer.produce(item);
        this_thread::sleep_for(chrono::milliseconds(dis(gen)));
    }
    cout << "快速生产者: " << id << " 完成" << endl;
}

void slow_producer(ThreadSafeBuffer& buffer, int id){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(200, 500);

    int item = 0;
    for(int i = 0; i < 10; ++i){
        item = id * 100 + i;
        buffer.produce(item);
        this_thread::sleep_for(chrono::milliseconds(dis(gen)));
    }
    cout << "慢速生产者: " << id << " 完成" << endl;
}

// 模拟消费者的不同消费速度
void fast_consumer(ThreadSafeBuffer& buffer, int id){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 150);

    while(true){
        int item = buffer.consume();
        if(item == -1) break;
        cout << "快速消费者: " << id << " 消费: " << item << endl;
        this_thread::sleep_for(chrono::milliseconds(dis(gen)));
    }
    cout << "快速消费者: " << id << " 完成" << endl;
}

void slow_consumer(ThreadSafeBuffer& buffer, int id){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(200, 500);

    while(true){
        int item = buffer.consume();
        if(item == -1) break;
        cout << "慢速消费者: " << id << " 消费: " << item << endl;
        this_thread::sleep_for(chrono::milliseconds(dis(gen)));
    }
    cout << "慢速消费者: " << id << " 完成" << endl;
}

void conditional_variable_test(){
    ThreadSafeBuffer buffer;
    vector<thread> producers;
    vector<thread> consumers;

    cout << "=== 开始演示条件变量的优势 ===" << endl;
    cout << "缓冲区大小限制: " << buffer.get_buffer_capacity() << endl;
    cout << "观察: 当缓冲区满时，快速生产者会等待慢速消费者" << endl;
    cout << "观察: 当缓冲区空时，快速消费者会等待慢速生产者" << endl;
    cout << endl;

    int num_system_threads = thread::hardware_concurrency();
    int num_threads_per_type = num_system_threads / 4;
    for(int i = 0; i < num_system_threads; ++i){
        // 创建不同速度的生产者
        producers.emplace_back(thread(fast_producer, ref(buffer), i));
        producers.emplace_back(thread(slow_producer, ref(buffer), i+num_threads_per_type));
    }

    // 创建不同速度的消费者
    for(int i = 2 * num_threads_per_type; i < 3 * num_threads_per_type; ++i){
        consumers.emplace_back(thread(fast_consumer, ref(buffer), i));
        consumers.emplace_back(thread(slow_consumer, ref(buffer), i+num_threads_per_type));
    }

    // 让系统运行一段时间
    this_thread::sleep_for(chrono::seconds(20));


    // 停止生产和消费
    cout << endl;
    cout << "=== 停止生产和消费 ===" << endl;
    buffer.stop_producing();
    

    // 等待所有线程完成
    for(auto& t : producers) t.join();
    for(auto& t : consumers) t.join();

    cout << "=== 演示结束 ===" << endl;

}