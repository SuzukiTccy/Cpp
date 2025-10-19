#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void openFileTest(){

    // 写入文件
    fstream file;
    file.open("test.dat", ios::out | ios::trunc); // ios::out: 以输出模式打开文件，表示我们可以向文件写入数据
                                                  // ios::trunc: 如果文件已存在，则清空文件内容；如果文件不存在，则创建新文件
    if (!file){
        cerr << "Open file error !" << endl;
        return;
    }
    string name;
    cout << "Please enter your name: "; // ccy
    getline(cin, name);
    file << name << endl; 
    int age;
    cout << "Please enter your age: "; // 26
    cin >> age;
    cin.ignore();
    file << age << endl; // be written in as string
    file.close();

    // 读取文件
    file.open("test.dat", ios::in); // ios::in: 以输入模式打开文件，表示我们可以从文件读取数据
    string f;
    file >> f;
    cout << "Your name: " << f << endl;
    file >> f;
    cout << "Your age: " << f << endl;
    file.close();
    
    // 结合使用读写文件和定位指针
    fstream outfile;
    outfile.open("testout.dat", ios::out | ios::trunc);
    file.open("test.dat", ios::in);
    file.seekg(0, ios::beg); // 定位到 file 的起始的第0个字节
                             // ios::beg: 文件开头 
                             // ios::cur: 当前位置
                             // ios::end: 文件结尾
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

    // 定位指针的使用
    file.open("test.dat", ios::in);
    file.seekg(2, ios::beg);  // 定位到 file 的起始的第2个字节
    file >> f;
    cout << "f:" << f << endl; // output: y
    file.seekg(2, ios::cur);  // 定位到 file 的当前流的往后的第2个字节
    file >> f;
    cout << "f:" << f << endl; // output: 6
    file.seekg(ios::end); // 定位到 file 的末尾的往前的第0个字节
    file >> f; // 注意: >> 会跳过空白字符(空格, 制表符, 换行符)
    cout << "f:" << f << endl; // y, the pointer point to the first string, so the end of ccy is 'y'
    file.close();

}



