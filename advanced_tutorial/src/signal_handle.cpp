#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;


void SignalHandler(int signum){
    cout << "Interrupt Signal (" << signum << ")" << endl;

    exit(signum); // exit program
}


void signalHandleTest(){

    signal(SIGINT, SignalHandler); // sign the SIGINT signal and signal Handler function

    int i=0;
    while(++i){
        cout << "Go to sleep ..." << endl;
        sleep(1);
        if (i == 4) raise(SIGINT); // 抛出SIGINT信号
    }
}

