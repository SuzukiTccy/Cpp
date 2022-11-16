#include<iostream>
#include<vector>
#include<string>
using namespace std;


template <typename T>
inline T const& Max(T const& a, T const& b){
    return a > b ? a:b;
}



template <class T>
class Stack{
    private:
        vector<T> elems;
    
    public:
        typedef int stackLengthType;
        Stack(): elems(){}
        Stack(vector<T> const &v){
            elems = v;
        }
        void Push(T const& elem); // push into the stack
        void Pop(); // pop from the stack
        T Top() const;  // return the top element of stack
        bool empty() const{ // if stack is empty
            return elems.empty();
        }
        stackLengthType GetLength() const{ // why must declare 'const'?
                                           // because LengthMethod() use constant reference to Stack object
                                           // and it call the member function GetLength().
                                           // if having not 'const', the complier cannot guarantee that 
                                           // calling LengthMethod() will not change the constant reference to Stack object 
            return elems.size();
        }
};

template <class T>
inline void Stack<T>::Push(T const& elem){
    elems.push_back(elem);
}

template <class T>
inline void Stack<T>::Pop(){
    if (empty()){
        throw out_of_range("Stack<>::Pop(): empty stack!");
    }
    elems.pop_back();
}

template <class T>
inline T Stack<T>::Top() const{
    if (empty()){
        throw out_of_range("Stack<>::Pop(): empty stack!");
    }
    return elems.back();
}



template <typename T>
inline T LengthMethod(Stack<T> const &mystack){
    typedef typename Stack<T>::stackLengthType stackLengthType; // 'typename' tell the compiler that 
                                                                // Stack<T>::stackLengthType is a Type
                                                                // not the member function or variable.
    stackLengthType length = mystack.GetLength();
    return length;
}





void templateTest(){

    cout << "============The test of function template=========" << endl;
    int a1=5, b1=6;
    cout << "Max(a1, b1) = " << Max(a1, b1) << endl;

    double a2=5.5, b2=6.6;
    cout << "Max(a2, b2) = " << Max(a2, b2) << endl;

    string a3="abc", b3="efg";
    cout << "Max(a3, b3) = " << Max(a3, b3) << endl;


    cout << "============The test of class template=========" << endl;
    try{
        Stack<int> iStack(vector<int> {1,2,3}); // definited in the try{}, meaning it's a local variable
        Stack<string> sStack(vector<string> {});

        iStack.Push(5);
        cout << "iStack.Top() = " << iStack.Top() << endl;

        sStack.Push("World!");
        cout << "sStack.Top() = " << sStack.Top() << endl;

        cout << "The lenght of iStack is " << LengthMethod(iStack) << endl;

        iStack.Pop();
        sStack.Pop();
        sStack.Pop();


    }catch (exception &e){
        cerr << e.what() << endl;
    }

    


}
