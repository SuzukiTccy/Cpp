#include<iostream>
#include<thread>
using namespace std;

void printHello(int count){
    for(int i=0;i<count;i++){
        cout<<"Hello World!"<<endl;
    }
}



int main(){
    thread t1(printHello,5);
    t1.join();
    return 0;
}