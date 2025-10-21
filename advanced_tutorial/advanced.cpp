#include <iostream>
#include "AdvancedFunc.h"
using namespace std;





int main(){
/*=======================file and stream========================*/
    cout << "<===========file and stream===========>" << endl;
    #if 0
        openFileTest();
        cout << endl;
    #endif


/*=======================exception handing========================*/
    cout << "<===========exception handing===========>" << endl;
    #if 0
    exceptionTest();
    cout << endl;
    #endif


/*=======================dynamic memory space========================*/
    cout << "<===========dynamic memory space===========>" << endl;
    dynamicTest();
    cout << endl;


/*=======================namespace========================*/
    cout << "<===========namespace===========>" << endl;
    namespaceTest();
    cout << endl;
    

/*=======================template========================*/
    cout << "<===========template===========>" << endl;
    templateTest();
    cout << endl;


/*=======================preprocessor========================*/
    cout << "<===========preprocessor===========>" << endl;
    preprocessorTest();
    cout << endl;


/*=======================signal Handle========================*/
    cout << "<===========signal Handle===========>" << endl;
    // signalHandleTest();
    cout << endl;



/*=======================multi-thread========================*/
    cout << "<===========multi-thread===========>" << endl;
    cout << "<=====pthreadTest1()======>" << endl;
    // pthreadTest1();
    cout << endl;

    cout << "<=====pthreadTest2()======>" << endl;
    // pthreadTest2();
    cout << endl;

    cout << "<=====threadTest1()======>" << endl;
    // threadTest1();
    cout << endl;

    cout << "<=====threadTest2()======>" << endl;
    threadTest2();
    cout << endl;



/*=======================STL========================*/
    cout << "<===========STL===========>" << endl;
    cout << "<===========vector===========>" << endl;
    vec();
    cout << endl;


    return 0;
}