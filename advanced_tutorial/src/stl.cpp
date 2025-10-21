#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;



void vec(){
    vector<int> vec;
    int i;

    cout << "the original vec.size() = " << vec.size() << endl;

    for(i = 0; i < 5; i++){
        vec.push_back(i);
    }
    cout << "extended vec.size() = " << vec.size() << endl;

    for(i = 0; i < 5; ++i){
        cout << "vec[" << i << "] = " << vec[i] << endl;
    }

    vector<int>::iterator v = vec.begin(); // vector的迭代器v, 并将其初始化为指向vector的第一个元素
    while(v != vec.end()){
        cout << "v = " << *v << endl;
        ++v;
    }


    vector<int> vvv;
    cout << "vvv.size() = " << vvv.size() << "\t" 
    << "vvv.capacity() = " << vvv.capacity() << endl; // capacity()返回的是vector的容量, 即vector中最多可以容纳的元素个数

    vvv.reserve(10); // reserve()函数用于增加vector的容量, 使其至少能够容纳n个元素, 但不改变size
    cout << "vvv.size() = " << vvv.size() << "\t" 
    << "vvv.capacity() = " << vvv.capacity() << endl;

    vvv.resize(5); // resize()函数将vector的size调整为5, 但不会减少已分配的内存空间
    vvv.push_back(1);
    cout << "vvv.size() = " << vvv.size() << "\t" 
    << "vvv.capacity() = " << vvv.capacity() << endl;

    cout << endl;

    try{
        // 这里没有抛出异常, 因为[]操作符不检查边界
        cout << "vvv[10] = " << vvv[10] << endl; // output: 0
        cout << "vvv[11] = " << vvv[11] << endl; // output: 0 
    }catch(exception &e){
        cout << "out of range!!!" << endl;
    }

    cout << endl;

    try{
        // 这里会抛出异常, 因为at()函数会检查边界
        cout << "vvv.at(10) = " << vvv.at(10) << endl;
    }catch(exception &e){
        cout << "捕获到异常" << "out of range!!!" << endl;
    }

    cout << endl;
    
    vector<int>::iterator ve = vvv.begin();
    while(ve != vvv.end()){
        cout << "ve = " << *ve << endl;
        ++ve;
    }

}



