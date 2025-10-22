#include<iostream>
#include<memory>
using namespace std;

// <===================== unique_ptr示例 =======================>
void unique_ptr_example(){

    // 1. unique_ptr声明和初始化
    cout << "<======== unique_ptr声明和初始化 ========>" << endl;
    unique_ptr<int> uqp1 = make_unique<int>(10); // 推荐的初始化

    unique_ptr<int> uqp2(new int(20)); // 不推荐的初始化
    unique_ptr<int> uqp3;
    uqp3.reset(new int(30)); // 不推荐的初始化

    cout << "*uqp1 = " << *uqp1 << endl; // output: 10
    cout << "*uqp2 = " << *uqp2 << endl; // output: 20
    cout << "*uqp3 = " << *uqp3 << endl; // output: 30


    // 2. unique_ptr转移所有权
    cout << "<======== unique_ptr转移所有权 ========>" << endl;
    auto uqp4 = std::move(uqp1); // uqp1所有权转移给uqp4
    cout << "uqp1: " << uqp1.get() << endl; // output: nullptr
    cout << "*uqp4 = " << *uqp4 << endl; // output: 10


    // 3. unique_ptr释放资源
    cout << "<======== unique_ptr释放资源 ========>" << endl;
    int *intp = uqp4.release(); // uqp4释放资源，返回原始指针
    cout << "*intp = " << *intp << endl; // output: 10
    delete intp; // 释放原始指针

    // 4. unique_ptr重置资源
    cout << "<======== unique_ptr重置资源 ========>" << endl;
    uqp1.reset(new int(40)); // 重置资源
    cout << "*uqp1 = " << *uqp1 << endl; // output: 40

}