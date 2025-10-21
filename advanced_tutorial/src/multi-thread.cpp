#include <iostream>
#include <thread> // C++11 standard thread library
#include <pthread.h>
#include <string>
#include <unistd.h> // 作用: sleep function
using namespace std;

#define NUM_THREADS 10


void *sayHello(void *thread_id){ // return type and variable type must be void*
                                 // because pthread_create() require the function pointer
    int tid = *((int *)thread_id); 
    cout << "Hello World! Thread_id :" << tid << endl;
    pthread_exit(NULL); // exit thread
    
    return nullptr;
}


void pthreadTest1(){

    pthread_t threads[NUM_THREADS]; // 创立线程池
    int tids[NUM_THREADS];
    int ret;
    int i;
    for(i = 0; i < NUM_THREADS; ++i){
        // 如果这里核心速度很快, 那么可能终端打印不会乱序
        cout << "main(), create the thread:" << i << endl;
        tids[i] = i;

        ret = pthread_create(&threads[i], NULL, sayHello, (void *)&(tids[i]) );
        if(ret != 0){
            cout << "thread creater error: error_code=" << ret << endl;
        }
    }

    for(int i = 0; i < NUM_THREADS; ++i) {
        /*
            pthread_join():
            1. 如果不使用pthread_join，主线程可能会在子线程还没完成时就退出
            这可能导致子线程的任务没有完全执行完就被终止
            2. 线程之间同步
        */
        pthread_join(threads[i], NULL); // 等待线程结束
    }
    
}



struct thread_data{
    // 结构体默认public
    int thread_id;
    string message;
};


void *printdata(void *threadarg){
    thread_data *tdata;
    tdata = (thread_data *)(threadarg);
    cout << "Thread_id: " << tdata->thread_id << endl;
    cout << "message: " << tdata->message << endl;
    pthread_exit(NULL);

    return nullptr;
}

void pthreadTest2(){
    pthread_t treads[NUM_THREADS];
    thread_data tdata[NUM_THREADS];
    int i;
    int ret;
    for(i = 0; i<NUM_THREADS; ++i){
        cout << "main(), create thread: " << i << endl;
        tdata[i].thread_id = i;
        tdata[i].message = "This is message from thread " + to_string(i);
        ret = pthread_create(&treads[i], NULL, printdata, (void*)(&tdata[i])); // tdata[i]不是指针, 所以要用&取地址
    }
    pthread_exit(NULL);
}





void foo(int Z){
    for (int i=0; i<Z; ++i){
        cout << "Thread "<< this_thread::get_id() \
        << " use function pointer as the callable parameter" << endl;
    }
}

class thread_obj{
    public:
        void operator()(int x){
            for(int i=0; i<x; ++i){
                cout << "Thread " << this_thread::get_id() \
                << " use function object as callable parameter" << endl;
            }
        }
};


void threadTest1(){
    thread th1(foo, 5); // th1 用函数指针作为可调用参数, th1对象被创建时, 线程就开始运行
    thread th2{thread_obj(), 5}; // th2 用函数对象作为可调用参数, th2对象被创建时, 线程就开始运行

    auto f = [](int x){
        for(int i=0; i<x; i++){
            cout << "Thread " << this_thread::get_id() \
            << " use lambda expression as callable parameter" << endl;
        }
    };

    thread th3(f, 5);

    th1.join(); // main thread 等待 th1 结束
    th2.join(); // main thread 等待 th2 结束
    th3.join(); // main thread 等待 th3 结束

    unsigned int n = thread::hardware_concurrency();
    cout << n << " concurrent threads are supported" << endl;

}


#include <chrono> // C++11 standard time library
#include <mutex>  // C++11 standard mutex library
#include <vector>
#include <condition_variable> // C++11 standard condition_variable library
std::mutex mtx;
std::condition_variable_any cond;

static int ticket_total = 100;
void sell_ticket(int thread_id){
    while(true){
        mtx.lock();
        if(ticket_total <= 0){
            mtx.unlock();
            return;
        }
        --ticket_total;
        cout << "ticket_seller " << thread_id << " sell 1 ticket, "
        << "there are " << ticket_total << " tickets left " << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}



void threadTest2(){
    int ticket_seller = thread::hardware_concurrency();
    int i;
    vector<thread> threads;
    for(i = 0; i < ticket_seller; ++i){
        threads.push_back(thread(sell_ticket, i));
    }
    for(auto &t : threads){
        t.join();
    }

}






