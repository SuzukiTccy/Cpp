#include <iostream>
#include <functional>  // 必须包含的头文件
#include <vector>
#include <string>
using namespace std;



// <=============================以下是function的简单例子=================================>
// 普通函数
int add(int a, int b) {
    return a + b;
}

// 函数对象（仿函数）
struct Multiply {
    int operator()(int a, int b) const {
        return a * b;
    }
};

// lambda表达式
auto subtract = [](int a, int b) -> int {
    return a - b;
};

void simple_exp_function() {
    // 声明一个function，接受两个int参数，返回int
    function<int(int, int)> func;
    
    // 包装普通函数
    func = add;
    cout << "add(10, 5): " << func(10, 5) << endl;  // 输出: 15
    
    // 包装函数对象
    func = Multiply();
    cout << "Multiply(10, 5): " << func(10, 5) << endl;  // 输出: 50
    
    // 包装lambda表达式
    func = subtract;
    cout << "subtract(10, 5): " << func(10, 5) << endl;  // 输出: 5
    
    // 检查是否包含可调用目标
    if (func) {
        cout << "func包含有效的可调用对象" << endl;
    }
    
    // 重置为空的function
    func = nullptr;
    if (!func) {
        cout << "func现在是空的" << endl;
    }
}




// <=============================以下是function的复杂例子=================================>
class Calculator {
private:
    string name;
    
public:
    Calculator(const string& n) : name(n) {}
    
    double process(double a, double b, function<double(double, double)> op) {
        double result = op(a, b);
        cout << name << " 计算: " << a << " op " << b << " = " << result << endl;
        return result;
    }
};

// 回调函数示例
class Button {
private:
    string label;
    function<void()> onClick;
    
public:
    Button(const string& l) : label(l) {}
    
    void setOnClick(function<void()> handler) {
        onClick = handler;
    }
    
    void click() {
        cout << "按钮 '" << label << "' 被点击了！" << endl;
        if (onClick) {
            onClick();
        }
    }
};

void complicated_exp_function() {
    // 1. 在类中使用function作为回调
    Calculator calc("科学计算器");
    
    // 传递不同的操作
    calc.process(10, 3, [](double a, double b) { return a + b; });
    calc.process(10, 3, [](double a, double b) { return a * b; });
    calc.process(10, 3, [](double a, double b) { return a / b; });
    
    // 2. 事件处理示例
    Button btn("确定");
    int clickCount = 0;
    
    // 捕获外部变量的lambda
    btn.setOnClick([&clickCount]() {
        clickCount++;
        cout << "这是第 " << clickCount << " 次点击" << endl;
    });
    
    btn.click();
    btn.click();
    btn.click();
    
}

