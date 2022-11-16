#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace first_space{
    void func(){
        cout << "This is first_space!" << endl;
    }
}

namespace second_space{
    void func2(){
        cout << "This is second_space!" << endl;
    }
    namespace third_space{
        void func3(){
            cout << "This is third_space!" << endl;
        }
    }
}

using namespace first_space; // can use func() directly
using namespace second_space::third_space; // can use func3() directly
void namespaceTest(){
    func();
    second_space::func2();
    func3();

}