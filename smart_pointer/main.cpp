#include<iostream>
#include<memory>
#include<fstream>
using namespace std;

void test_unique_ptr(){
    cout << "<=======unique_ptr========>" << endl;
    // unique_ptr指针构造
    unique_ptr<int> ptr = make_unique<int>(10);
    cout<<"*ptr="<<*ptr<<endl;

    // unique_ptr指针转移
    unique_ptr<int> ptr2 = std::move(ptr);
    cout<<"*ptr2="<<*ptr2<<endl; // 输出10
    if(ptr == nullptr){
        cout << "ptr is nullptr" << endl; // 输出ptr is nullptr
    }

    // unique_ptr指针重置资源
    ptr2.reset(new int(30));
    cout << "*ptr2=" << *ptr2 << endl; // 输出30

    // unique_ptr指针释放资源
    int* ptr3 = ptr2.release(); // 释放资源，但不会删除，返回普通指针
    cout << "*ptr3=" << *ptr3 << endl; // 输出30
    delete ptr3;
}


void shared_deleter(fstream *file){
    if (file && file->is_open()){
        file->close();
        cout << "file closed" << endl;
    }
}

void test_shared_ptr(){
    cout << "<=======shared_ptr========>" << endl;
    // shared_ptr指针构造
    shared_ptr<int> ptr = make_shared<int>(10);
    cout << "*ptr=" << *ptr << endl;

    // shared_ptr引用
    shared_ptr<int> ptr1 = ptr;
    cout << "ptr.use_count() = " << ptr.use_count() << endl;
    cout << "ptr1.use_count() = " << ptr1.use_count() << endl;

    // shared_ptr重置和释放
    ptr.reset(new int(20));
    cout << "*ptr=" << *ptr << endl; // 输出20
    ptr1.reset();
    cout << "ptr.use_count() = " << ptr.use_count() << endl; // 输出1
    cout << "ptr1.use_count() = " << ptr1.use_count() << endl; // 输出0
    ptr.reset();
    cout << "ptr.use_count() = " << ptr.use_count() << endl; // 输出0
    cout << "ptr1.use_count() = " << ptr1.use_count() << endl; // 输出0

    // shared_ptr自定义删除器
    shared_ptr<fstream> ptr2(new fstream("test.txt", ios::out), shared_deleter);
    if (ptr2){
        ptr2->write("hello world", 11);
    }

}

void test_weak_ptr(){
    cout << "<=======weak_ptr========>" << endl;
    // weak_ptr指针构造
    shared_ptr<int> ptr = make_shared<int>(10);
    weak_ptr<int> wptr = ptr;
    cout << "*ptr=" << *ptr << endl;
    cout << "ptr.use_count() = " << ptr.use_count() << endl; // 输出1
    cout << "wptr.use_count() = " << wptr.use_count() << endl; // 输出1
    cout << "weak ptr has been expired?" << wptr.expired() << endl; // 输出0

    // weak_ptr指针转换
    shared_ptr<int> ptr2 = wptr.lock();
    if (ptr2){
        cout << "*ptr2=" << *ptr2 << endl; // 输出10
    }else{
        cout << "The ordinary object is been destroyed" << endl;
    }
    cout << "ptr.use_count() = " << ptr.use_count() << endl; // 输出2, ptr和ptr2都指向同一个对象
    cout << "wptr.use_count() = " << wptr.use_count() << endl; // 输出2, weak_ptr的use_count()与shared_ptr的use_count()相同
    cout << "ptr2.use_count() = " << ptr2.use_count() << endl; // 输出2, ptr和ptr2都指向同一个对象


    ptr.reset();
    cout << "ptr.use_count() = " << ptr.use_count() << endl; // 输出0
    cout << "ptr2.use_count() = " << ptr2.use_count() << endl; // 输出1
    cout << "wptr.use_count() = " << wptr.use_count() << endl; // 输出1, 因为ptr2存在

    ptr2 = wptr.lock();
    if (ptr2){
        cout << "*ptr2=" << *ptr2 << endl; // 输出10
    }else{
        cout << "The ordinary object is been destroyed" << endl;
    }

    cout << "weak ptr has been expired?" << wptr.expired() << endl; // 输出0

    ptr2.reset();
    cout << "ptr.use_count() = " << ptr.use_count() << endl; // 输出0
    cout << "wptr.use_count() = " << wptr.use_count() << endl; // 输出0
    cout << "weak ptr has been expired?" << wptr.expired() << endl; // 输出1

}



int main(){
    test_unique_ptr();
    test_shared_ptr();
    test_weak_ptr();

    return 0;
}