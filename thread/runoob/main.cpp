#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

void printHello(int count, int thread_id){
    for(int i=0;i<count;i++){
        cout<<"Thread_id "<< thread_id << ": Hello World(func)! "<< i << endl;
    }
}

class printHelloClass{
public:
    void operator()(int count, int thread_id) const {
        for(int i=0;i<count;i++){
            
            cout<<"Thread_id "<< thread_id << ": Hello World(class)! "<< i << endl;
        }
    }
};

mutex mtx; // 全局互斥锁

void printHello_mutex(int count, int thread_id){
    for(int i=0;i<count;i++){
        mtx.lock(); // 加锁
        cout<<"Thread_id "<< thread_id << ": Hello World(func)! "<< i << endl;
        mtx.unlock(); // 解锁
    }
}

class printHelloClass_mutex{
public:
    void operator()(int count, int thread_id) const {
        for(int i=0;i<count;i++){
            mtx.lock(); // 加锁
            cout<<"Thread_id "<< thread_id << ": Hello World(class)! "<< i << endl;
            mtx.unlock(); // 解锁
        }
    }
};


int main(){
    cout << "<=========多线程示例=========>" << endl;
    int num = 15;
    thread t1(printHello, 5, 1);
    thread t2(printHelloClass(), 10, 2);
    thread t3([](int count, int thread_id){
        for(int i=0;i<count;i++){
            cout<<"Thread_id "<< thread_id << ": Hello World(lambda)! "<< i << endl;
        }
    }, ref(num), 3);

    t1.join(); // 等待t1执行完毕, 实操中，主线程并没有等待t1执行完，这可能跟操作系统的线程调度器有关
    t2.detach(); // 线程分离，主线程不会等待子线程执行完毕
    t3.detach(); // 线程分离，主线程不会等待子线程执行完毕

    this_thread::sleep_for(chrono::seconds(3)); // 主线程休眠2.5秒，等待t2,t3执行完毕

    cout << "<=========互斥锁mutex示例=========>" << endl;
    thread t4(printHello_mutex, 5, 4);
    thread t5(printHelloClass_mutex(), 10, 5);
    thread t6([](int count, int thread_id){
        for(int i=0;i<count;i++){
            mtx.lock(); // 加锁
            cout<<"Thread_id "<< thread_id << ": Hello World(lambda)! "<< i << endl;
            mtx.unlock(); // 解锁
        }
    }, 15, 6);

    t4.join();
    t5.join();
    t6.join();

    this_thread::sleep_for(chrono::seconds(3)); // 主线程休眠2.5秒，等待全部线程执行完毕

    return 0;
}