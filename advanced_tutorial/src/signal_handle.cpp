#include <iostream>
#include <csignal>
#include <unistd.h> //作用：提供访问系统参数的函数，如访问系统时间、进程优先级、终端控制等，这里是sleep()
using namespace std;


void SignalHandler(int signum){
    cout << "Interrupt Signal (" << signum << ")" << endl;

    exit(signum); // exit program
}


void signalHandleTest(){

    signal(SIGINT, SignalHandler); // sign the SIGINT signal and signal Handler function

    int i = 0;
    while(++i){
        cout << "Go to sleep ..." << endl;
        sleep(1);
        if (i == 4) raise(SIGINT); // 抛出SIGINT信号
    }
}

