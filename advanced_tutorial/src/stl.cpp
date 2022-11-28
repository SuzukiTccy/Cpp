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

    vector<int>::iterator v = vec.begin();
    while(v != vec.end()){
        cout << "v = " << *v << endl;
        ++v;
    }


    vector<int> vvv;
    cout << "vvv.size() = " << vvv.size() << "\t" 
    << "vvv.capacity() = " << vvv.capacity() << endl;

    vvv.reserve(10);
    cout << "vvv.size() = " << vvv.size() << "\t" 
    << "vvv.capacity() = " << vvv.capacity() << endl;

    vvv.resize(5);
    vvv.push_back(1);
    cout << "vvv.size() = " << vvv.size() << "\t" 
    << "vvv.capacity() = " << vvv.capacity() << endl;


    try{
        cout << "vvv[10] = " << vvv[10] << endl;
        cout << "vvv[11] = " << vvv[11] << endl; // 11 is out of range, because 
    }catch(exception &e){
        cout << "out of range!!!" << endl;
    }


    vector<int>::iterator ve = vvv.begin();
    while(ve != vvv.end()){
        cout << "ve = " << *ve << endl;
        ++ve;
    }


}



