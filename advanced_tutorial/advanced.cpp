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
    #if 0
    signalHandleTest();
    #endif
    cout << endl;



/*=======================multi-thread========================*/
    cout << "<===========multi-thread===========>" << endl;
    cout << "<=====pthreadTest1()======>" << endl;
    #if 0
    pthreadTest1();
    #endif
    cout << endl;

    cout << "<=====pthreadTest2()======>" << endl;
    #if 0
    pthreadTest2();
    #endif
    cout << endl;

    cout << "<=====threadTest1()======>" << endl;
    #if 0
    threadTest1();
    #endif
    cout << endl;

    cout << "<=====threadTest2()======>" << endl;
    #if 0
    threadTest2();
    #endif
    cout << endl;



/*=======================STL========================*/
    cout << "<===========STL===========>" << endl;
    cout << "<===========vector===========>" << endl;
    vec();
    cout << endl;



/*=======================functional========================*/
    cout << "<===========functional===========>" << endl;
    cout << "<===========simple example===========>" << endl;
    simple_exp_function();
    cout << endl;

    cout << "<===========complicated example===========>" << endl;
    complicated_exp_function();
    cout << endl;



/*=======================bind========================*/
    cout << "<===========bind===========>" << endl;
    cout << "<===========simple example===========>" << endl;
    simple_exp_bind();
    cout << endl;

    cout << "<===========bind classFunction example===========>" << endl;
    classfunc_exp_bind();
    cout << endl;


/*======================= smart pointer========================*/
    cout << "<=========== unique_ptr ===========>" << endl;
    unique_ptr_example();
    cout << endl;

    cout << "<=========== shared_ptr ===========>" << endl;
    shared_ptr_example();
    cout << endl;

    cout << "<=========== weak_ptr ===========>" << endl;
    weak_ptr_example();
    cout << endl;



    return 0;
}