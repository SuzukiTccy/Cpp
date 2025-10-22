#include<iostream>
#include<vector>
#include<string>
using namespace std;


template <typename T>
inline T const& Max(T const& a, T const& b){
    return a > b ? a:b;
}

template <typename T1, typename T2> // 可以有多个参数，但是不能有默认参数
inline T2 const & Min(T1 const& a, T2 const& b){
    return a < b ? a:b;
}


// 手写一个栈的类模板
template <class T, class T2 = char> // 可以有默认参数
class Stack{
    private:
        vector<T> elems;
    
    public:
        typedef int stackLengthType;
        Stack(): elems(){} // 无参数构造函数
        
        // 复制构造函数
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
                                           // 因为第74行有个const引用的Stack对象调用了GetLength()函数
            return elems.size();
        }
};

// template <class T, class T2 = char> // 错误的，不能在类模版外的定义中指定默认参数
template <class T, class T2>
inline void Stack<T, T2>::Push(T const& elem){
    elems.push_back(elem);
}

template <class T, class T2>
inline void Stack<T, T2>::Pop(){
    if (this->empty()){
        throw out_of_range("Stack<>::Pop(): empty stack!");
    }
    elems.pop_back();
}

template <class T, class T2>
inline T Stack<T, T2>::Top() const{
    if (empty()){
        throw out_of_range("Stack<>::Pop(): empty stack!");
    }
    return elems.back();
}



template <typename T, typename T2>
inline T LengthMethod(Stack<T, T2> const &mystack){
    typedef typename Stack<T, T2>::stackLengthType stackLengthType; // 'typename' tell the compiler that 
                                                                // Stack<T>::stackLengthType is a Type
                                                                // not the member function or variable.
    stackLengthType length = mystack.GetLength();
    return length;
}


class CSON1 : public Stack<int, char>{
    // 非类模版的派生类，需要指定基类模版的参数
};


template <class T, class T2, class T3>
class CSON2 : public Stack<T, T2>{
    // 类模版的派生类，可以不指定基类模版的参数
};




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
        cout << "iStack.Top() = " << iStack.Top() << endl; // output: 5

        sStack.Push("World!");
        cout << "sStack.Top() = " << sStack.Top() << endl; // output: World!

        cout << "The lenght of iStack is " << LengthMethod(iStack) << endl; // output: 4

        iStack.Pop();
        sStack.Pop();
        sStack.Pop();


    }catch (exception &e){
        cerr << e.what() << endl;
    }

    


}
