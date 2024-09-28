#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void openFileTest(){
    fstream file;
    file.open("test.dat", ios::out | ios::trunc); // ios::out 打开文件用于写入。
    if (!file){                                   // ios::trunc 如果文件存在则先删除，然后创建一个新文件。
        cerr << "Open file error !" << endl;      // ios::in 打开文件用于读取。
        return;                                   // ios::app 打开文件用于追加。如果文件不存在，则会创建一个新文件。
    }                                             // ios::ate 打开文件后定位到文件末尾。
    string name;
    cout << "Please enter your name: "; // ccy
    getline(cin, name);
    file << name << endl; 
    int age;
    cout << "Please enter your age: "; // 23
    cin >> age;
    cin.ignore();
    file << age << endl; // be written in as string
    file.close();

    file.open("test.dat", ios::in);
    string f;
    file >> f;
    cout << "Your name: " << f << endl;
    file >> f;
    cout << "Your age: " << f << endl;
    file.close();
    
    fstream outfile;
    outfile.open("testout.dat", ios::out | ios::trunc);
    file.open("test.dat", ios::in);
    file.seekg(0, ios::beg); // 定位到 file 的起始的第0个字节
    string info[2] = {"Your name: ", "Your age: "};
    string s;
    int idx = 0;
    while(file >> s){
        s = info[idx] + s;
        cout << "s = " << s << endl;
        outfile << s << endl;
        ++idx;
    }
    outfile.close();
    file.close();



    file.open("test.dat", ios::in);
    file.seekg(2, ios::beg);  // 定位到 file 的起始的第2个字节
    file >> f;
    cout << "f:" << f << endl; // y
    file.seekg(2, ios::cur);  // 定位到 file 的当前流的往后的第2个字节
    file >> f;
    cout << "f:" << f << endl; // y
    file.seekg(ios::end);
    file >> f;  // 定位到 file 的末尾的往前的第0个字节
    cout << "f:" << f << endl; // y, the pointer point to the first string, so the end of ccy is 'y'
    file.close();

}



