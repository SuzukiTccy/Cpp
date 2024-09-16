#include <iostream>
using namespace std;

// 单例模式
class A
{
// static函数可以直接通过类名调用，不需要创建对象
// static函数内部不能使用非static成员变量和非static成员函数
// static函数内部不能使用this指针
public:
    static A& getInstance();
    int getval() const { return val; };
    void setval(int val) { this->val = val; };
private:
    int val;
    A(): val(0) {};
    A(const A& val) = delete; // 禁止拷贝构造
};

A& A::getInstance(){
    static A a;
    return a;
};

int main()
{   
    cout << A::getInstance().getval() << endl;
    A::getInstance().setval(10);
    cout << A::getInstance().getval() << endl;
    return 0;
}