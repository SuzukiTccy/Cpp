#include <iostream>
#include "AdvancedFunc.h"
using namespace std;





int main(){
/*=======================file and stream========================*/
    cout << "<===========file and stream===========>" << endl;
    openFileTest();


/*=======================exception handing========================*/
    cout << "<===========exception handing===========>" << endl;
    exceptionTest();


/*=======================dynamic memory space========================*/
    cout << "<===========dynamic memory space===========>" << endl;
    dynamicTest();


/*=======================namespace========================*/
    cout << "<===========namespace===========>" << endl;
    namespaceTest();
    

/*=======================template========================*/
    cout << "<===========template===========>" << endl;
    templateTest();


/*=======================preprocessor========================*/
    cout << "<===========preprocessor===========>" << endl;
    preprocessorTest();


/*=======================signal Handle========================*/
    cout << "<===========signal Handle===========>" << endl;
    // signalHandleTest();



/*=======================multi-thread========================*/
    cout << "<===========multi-thread===========>" << endl;
    cout << "<=====pthreadTest1()======>" << endl;
    // pthreadTest1();

    cout << "<=====pthreadTest2()======>" << endl;
    // pthreadTest2();

    cout << "<=====threadTest1()======>" << endl;
    // threadTest1();

    cout << "<=====threadTest2()======>" << endl;
    threadTest2();



/*=======================STL========================*/
    cout << "<===========STL===========>" << endl;
    cout << "<===========vector===========>" << endl;
    vec();


    return 0;
}