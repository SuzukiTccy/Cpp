#include<iostream>
using namespace std;


struct MyException : public exception{
    
    const char* what() const throw(){ // throw() means Exception Specification, 
                                      // specifies the Exception that what() can throw. throw() == noexcept
                                      // And the ISO C++17 not allow the dynamic exception specification.
                                      // the second "const" means that 
                                      // this function what() can't change the member variable.
        return "Division by zero condition!";
    }
};

double division(double a, double b){
    if (b == 0){
        throw MyException();
    }

    return a / b;
}

void exceptionTest(){
    double a,b;
    try{
        cout << "Please enter the dividend: ";
        cin >> a;
        cout << "Please enter the divisor: ";
        cin >> b;
        double c = division(a, b);
        cout << "the result is " << c << endl;
    }catch(MyException& e){ // My expception
        cout << e.what() << endl;
    }catch(exception& e){ // other expception
        cout << e.what() << endl;
    }


}