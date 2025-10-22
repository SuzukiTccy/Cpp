#include<iostream>
#include<memory>
#include<fstream>
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



// <===================== shared_ptr示例 =======================>
void shared_ptr_example(){

    // 1. shared_ptr声明和初始化
    cout << "<======== shared_ptr声明和初始化 ========>" << endl;
    shared_ptr<int> sp1 = make_shared<int>(10); // 推荐的初始化

    shared_ptr<int> sp2(new int(20)); // 不推荐的初始化
    shared_ptr<int> sp3;
    sp3.reset(new int(30)); // 不推荐的初始化

    cout << "*sp1 = " << *sp1 << endl; // output: 10
    cout << "*sp2 = " << *sp2 << endl; // output: 20
    cout << "*sp3 = " << *sp3 << endl; // output: 30


    // 2. shared_ptr引用计数
    cout << "<======== shared_ptr引用计数 ========>" << endl;
    cout << "sp1.use_count() = " << sp1.use_count() << endl; // output: 1
    shared_ptr<int> sp4 = sp1; // 引用计数+1
    cout << "sp1.use_count() = " << sp1.use_count() << endl; // output: 2
    cout << "sp4.use_count() = " << sp4.use_count() << endl; // output: 2


    // 3. shared_ptr重置和释放资源
    cout << "<======== shared_ptr重置释放资源 ========>" << endl;
    sp4.reset(); // 释放资源, 引用计数-1
    cout << "sp1.use_count() = " << sp1.use_count() << endl; // output: 1
    cout << "sp4.use_count() = " << sp4.use_count() << endl; // output: 0

    sp1.reset(new int(40)); // 重置资源
    cout << "*sp1 = " << *sp1 << endl; // output: 40
    

    // 4. shared_ptr交换资源
    cout << "<======== shared_ptr交换资源 ========>" << endl;
    shared_ptr<int> sp5 = make_shared<int>(50);
    cout << "*sp1 = " << *sp1 << endl; // output: 40
    cout << "*sp5 = " << *sp5 << endl; // output: 50
    sp1.swap(sp5);
    cout << "sp1.swap(sp5)之后" << endl;
    cout << "*sp1 = " << *sp1 << endl; // output: 50
    cout << "*sp5 = " << *sp5 << endl; // output: 40


    // 5. shared_ptr自定义删除器
    cout << "<======== shared_ptr自定义删除器 ========>" << endl;
    void shared_deleter(fstream *file); // 自定义删除器

    shared_ptr<fstream> ptr2(new fstream("test.txt", ios::out), shared_deleter);
    if (ptr2){
        ptr2->write("hello world", 11);
    }

}


void shared_deleter(fstream *file){
    if(file && file->is_open()){
        file->close();
        cout << "file closed" << endl;
    }
    delete file;
}