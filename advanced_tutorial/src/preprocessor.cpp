#include<iostream>
using namespace std;

#define PI 3.1415926
#define MAX(a,b) (a>b? a:b)
#define DEBUG true
#define STR(x) #x
#define CONCAT(a,b) a ## b


void preprocessorTest(){

    #ifdef DEBUG

        cout << "<=========create the symbol constant=========>" << endl;
        cout << "The value of PI is " << PI << endl; // usually call the 'PI' as macro
        cout << endl;


        cout << "<=========macor with parameter=========>" << endl;
        cout << "MAX(2,1) = " << MAX(2,1) << endl;
        cout << endl;


        cout << "<=========# and ##=========>" << endl;
        cout << "STR(444334) = " << STR(444334) << endl; //operator # convert into string
        int ab = 100;
        cout << "CONCAT(a,b) = " << CONCAT(a,b) << endl; // ## concat the vriable name 'a' and 'b', and the result is ab
                                                         // so cout << CONCAT(a,b) == cout << ab
                                                         // 连接的是变量名，而不是字符串
        cout << endl;
        

        cout << "=========C++ predefined macro=========" << endl;
        cout << "Value of __LINE__ : " << __LINE__ << endl;
        cout << "Value of __FILE__ : " << __FILE__ << endl;
        cout << "Value of __DATE__ : " << __DATE__ << endl;
        cout << "Value of __TIME__ : " << __TIME__ << endl;  

    #endif


}
