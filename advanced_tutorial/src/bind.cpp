#include <iostream>
#include <functional>
#include <string>
using namespace std;
using namespace std::placeholders;  // 用于 _1, _2, _3...


/*
    std::bind 是一个函数适配器，它可以：

    - 绑定参数：将可调用对象的某些参数固定为特定值

    - 重新排序参数：改变参数的顺序

    - 部分应用：创建参数更少的新函数

    - 绑定成员函数：将成员函数绑定到特定对象
*/



// <=============================以下是bind的简单例子=================================>
// 普通函数
void printNumbers(int a, int b, int c) {
    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
}

int multiply(int a, int b, int c) {
    return a * b * c;
}

void simple_exp_bind() {
    // 1. 绑定固定参数
    auto boundFunc1 = bind(printNumbers, 10, 20, 30);
    boundFunc1();  // 输出: a=10, b=20, c=30
    
    // 2. 使用占位符
    auto boundFunc2 = bind(printNumbers, _1, _2, 100);  // 固定第三个参数
    boundFunc2(1, 2);  // 输出: a=1, b=2, c=100
    
    auto boundFunc3 = bind(printNumbers, _2, _1, 50);   // 交换前两个参数
    boundFunc3(10, 20);  // 输出: a=20, b=10, c=50
    
    // 3. 绑定返回值
    auto boundMultiply = bind(multiply, _1, 5, 2);  // 固定第二、三个参数
    cout << "boundMultiply(3): " << boundMultiply(3) << endl;  // 3*5*2 = 30
    
}


// <=============================以下是bind的绑定成员函数例子=================================>

class Person {
private:
    string name;
    int age;
    
public:
    Person(const string& n, int a) : name(n), age(a) {}
    
    void introduce(const string& greeting) const {
        cout << greeting << "! 我是 " << name << ", " << age << " 岁。" << endl;
    }
    
    void setName(const string& newName) {
        name = newName;
        cout << "名字改为: " << name << endl;
    }
    
    string getName() const {
        return name;
    }
};

void classfunc_exp_bind() {
    Person alice("Alice", 25);
    Person bob("Bob", 30);
    
    // 1. 绑定成员函数到特定对象
    auto aliceIntro = bind(&Person::introduce, &alice, _1);
    aliceIntro("你好");  // 相当于 alice.introduce("你好")
    
    auto bobIntro = bind(&Person::introduce, &bob, "Hello");
    bobIntro();  // 相当于 bob.introduce("Hello")
    
    // 2. 绑定setter函数
    auto setAliceName = bind(&Person::setName, &alice, _1);
    setAliceName("Alice Smith");
    
    // 3. 绑定getter函数
    auto getAliceName = bind(&Person::getName, &alice);
    cout << "Alice的名字: " << getAliceName() << endl;
    
}