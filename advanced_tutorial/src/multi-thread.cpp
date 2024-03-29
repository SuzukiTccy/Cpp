#include <iostream>
#include <thread> // C++11 standard thread library
#include <pthread.h>
#include <string>
#include <unistd.h>
using namespace std;

#define NUM_THREADS 5


void *sayHello(void *thread_id){

    int tid = *((int *)thread_id); // int * cast type
    cout << "Hello World! Thread_id :" << tid << endl;
    pthread_exit(NULL);
    
    return nullptr;
}


void pthreadTest1(){

    pthread_t treads[NUM_THREADS];
    int tids[NUM_THREADS];
    int ret;
    int i;
    for(i = 0; i < NUM_THREADS; ++i){
        cout << "main(), create the thread:" << i << endl;
        tids[i] = i;

        ret = pthread_create(&treads[i], NULL, sayHello, (void *)&(tids[i]) );
        if(ret != 0){
            cout << "thread creater error: error_code=" << ret << endl;
        }
    }
    pthread_exit(NULL);

}



struct thread_data{
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
        tdata[i].message = "This is message";
        ret = pthread_create(&treads[i], NULL, printdata, (void*)(&tdata[i]));
    }
    pthread_exit(NULL);
}





void foo(int Z){
    for (int i=0; i<Z; ++i){
        cout << "Thread "<< this_thread::get_id() << " use function pointer as the callable parameter" << endl;
    }
}

class thread_obj{
    public:
        void operator()(int x){
            for(int i=0; i<x; ++i){
                cout << "Thread " << this_thread::get_id() <<" use function object as callable parameter" << endl;
            }
        }
};


void threadTest1(){
    thread th1(foo, 3);
    thread th2{thread_obj(), 3};

    auto f = [](int x){
        for(int i=0; i<x; i++){
            cout << "Thread " << this_thread::get_id() << " use lambda expression as callable parameter" << endl;
        }
    };

    thread th3(f, 3);

    th1.join();
    th2.join();
    th3.join();

    unsigned int n = thread::hardware_concurrency();
    cout << n << " concurrent threads are supported" << endl;


}


#include <chrono>
#include <mutex>
#include <vector>
#include <condition_variable>
std::mutex mtx;
std::condition_variable_any cond;

static int ticket_total = 100;
void sell_ticket(int thread_id){
    while(ticket_total > 0){
        mtx.lock();
        --ticket_total;
        if(ticket_total < 0){ // avoiding some thread pass the the judgement statement, 
                              // but when execute '--ticket_total', 
                              // the public resource 'ticket_total' is < 0,
                              // because the other thread change it.
            mtx.unlock();
            return;
        }
        cout << "Wicket " << thread_id << " sell a ticket, " 
        << "there are " << ticket_total << " tickets left " << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}



void threadTest2(){
    int wicket_num = thread::hardware_concurrency();
    int i;
    vector<thread> threads;
    for(i = 0; i < wicket_num; ++i){
        threads.push_back(thread(sell_ticket, i));
    }
    for(auto &t : threads){
        t.join();
    }

}






