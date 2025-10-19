#include<iostream>
using namespace std;


/*=======================C++ class and object========================*/
class Box{
    private:
        char father;
        int *ptr;
    
    protected:
        double length;
        double breadth;
        double height;

    public:
        // static Member
        static int objectcount;
        static int getObjectcount(){ return objectcount; } // 静态函数作用：
                                                           // 1. 可以在没有对象实例的情况下调用
                                                           // 2. 只能访问静态成员变量和其他静态成员函数，不能访问非静态成员变量和非静态成员函数

        // Constructor
        Box(): length(0), breadth(0), height(0), ptr(nullptr) { ptr = new int; *ptr = 0; }

        Box(double l, double b, double h, int len): length(l), breadth(b), height(h)
        {
            ptr = new int;
            *ptr = len; // if the formal parameters name is same to the member variables,
                        // then use the 'this' pointer
            objectcount++;
            cout << "The object is be created!" << endl;
        }

        Box(const Box &bbox){ // if the class have the pointer variables, u must to difine a copy constructor
            cout << R"((Call the copy constructor))" << endl;
            ptr = new int;
            *ptr = *bbox.ptr;

            length = bbox.length;   // if build a copy constructor function, need to define all the member variables
            breadth = bbox.breadth; // or they will be defined as the random values.
            height = bbox.height;
        }

        // Member function declaration and definition
        void setlength(double l){ length = l; } // inline function
        void setbreadth(double b){ breadth = b; }
        void setheight(double h){ height = h; }
        double getVolume()const {
            return length * breadth * height; 
        }
        int getptr() const { return *ptr; }
        double getlength() const { return length; }


        virtual ~Box(){
            delete ptr;
            ptr = nullptr;
            objectcount--;
            cout << R"((delete the Box object !))" << endl;
        }

        friend void getBoxLenFriend(const Box& b);
        friend class FriendOfBox;

};

int Box::objectcount = 0;

double getBoxVolume(const Box &b){
    double v = b.getVolume();
    return v;
}

void classBoxTest(){
    Box box1(3.00, 4.00, 5.00, 1);
    box1.setlength(1.00);
    box1.setbreadth(2.00);
    box1.setheight(3.00);

    double volume = ::getBoxVolume(box1); // global function getBoxVolume
    cout << "volume = " << volume << endl;

}

void getBoxLenFriend(const Box& b){
    cout << "This is the friend function of class Box:" << endl;
    cout << "the protected variable of b length = " << b.length << endl;
}

class FriendOfBox{
    public:
    void getBoxLen(const Box& b){
        cout << "This is the friend class member function of class Box:" << endl;
        cout << "the protected variable of b length = " << b.length << endl;
    }
};

void friendofBoxTest(){
    void getBoxLenFriend(const Box&);
    Box box1(3.00, 4.00, 5.00, 1);
    cout << "box1.getlength() = " << box1.getlength() << endl;
    FriendOfBox fb;
    getBoxLenFriend(box1);
    fb.getBoxLen(box1);

}


void PtrBoxTest(){
    Box box1(3.00, 4.00, 5.00, 1);
    Box* p = &box1;
    cout << "p->getVolume() = " << p->getVolume() << endl;
}


void staticMemberTest(){
    Box box1(3.00, 4.00, 5.00, 1);
    cout << "Created object number = " << Box::objectcount << endl;
    Box box2(3.00, 5.00, 4.00, 4);
    cout << "Created object number = " << Box::getObjectcount() << endl;
}



class smallBox: virtual public Box{
    // 虚继承，用于解决多继承中，父类成员变量被多次继承的问题（钻石继承）
    // 虚继承是指，在派生类中，通过virtual关键字声明继承的基类，使得派生类和基类共享同一个基类对象
    // 虚继承的基类子对象，在派生类中只有一个，避免了基类成员变量被多次继承，于是有多个副本的问题
    private:
        double smallLength;
        double smallBreath;
    protected:
        double length;
    public:
        void setsmallLength(double l){ length = l; }
        // constructor can't be inherited
        smallBox(): Box(), smallLength(0), smallBreath(0), length(0) {}
        smallBox(double l, double b, double h, int len, double sb, double sblength = 1.44): 
        Box(l, b, h, len), smallLength(1.33), smallBreath(sb), length(sblength)
        {
            cout << "The object is be created!" << endl;
        }
        ~smallBox(){
            cout << R"((delete the smallBox object! ))" << endl;
        }
};

double getSmallBoxVolume(smallBox &b){
    double v = b.getVolume();
    return v;
}

void classSmallBoxTest(){
    smallBox smbox1(3.00, 4.00, 5.00, 2, 6.00, 1.55);
    smbox1.setsmallLength(1.00);
    smbox1.setbreadth(2.00);
    smbox1.setheight(3.00);

    double volume = ::getBoxVolume(smbox1); // global function getBoxVolume()
    cout << "volume = " << volume << endl;
    cout << "smbox1.getptr() = " << smbox1.getptr() << endl; // child class can call the parent class non-private member function
    cout << "smbox1.Box::getlength() = " << smbox1.Box::getlength() << endl; // can use :: to access the parent member, 
                                                                             // when the parent class has the same name members to the child
                                                                             // the output is the parent class protected member 'length'

    cout << "smbox1.getlength() = " << smbox1.getlength() << endl; // the output is also the parent class protected member 'length'
                                                                   // because the child class dont rewrite the getlength() function

}                                                                        



/*=======================C++ inherit========================*/
class tiny: virtual public Box{
    private:
        double tiny_private;
    public:
        tiny(): Box(), tiny_private(0) {}

        tiny(double l, double b, double h, int len, double tp = 0):
        Box(l, b, h, len), tiny_private(tp){}

        ~tiny(){
            cout << R"((delete the tiny object! ))" << endl;
        }

};


class tinyBox : virtual public smallBox, virtual public tiny{ // multiple inherit, unrecommend
    private:
        double tinybreath;
        double tinyheight;
        double tinylength;

    public:
        tinyBox(double l, double b, double h, int len, 
                double sb, double tb, double th, double tl, double tp = 0):
        smallBox(l, b, h, len, sb), 
        tiny(l, b, h, len, tp), 
        tinybreath(tb), tinyheight(th), tinylength(tl)
        {
            cout << "The object is be created!" << endl;
        }
        ~tinyBox(){
            cout << R"((delete the tinyBox object! ))" << endl;
        }

};


void inheritTest(){
    tinyBox tb(3.00, 4.00, 5.00, 2, 6.00, 0.1, 0.2, 0.3);
    cout << "tb.getlength() = " << tb.getlength() << endl; // 实际上调用的是最上层基类Box的getlength()函数
                                                           // 因为smallBox和tiny类都没有重写getlength()函数
}



/*=======================C++ operator and function overloading========================*/
class OverLD{
    private:
        int old;
        int *len;
    public:
        void setold(int old){ this->old = old; }
        void setlen(int len){ *(this->len) = len; }
        void print(int a){ cout << "a = " << a << endl; }
        void print(double d){ cout << "d = " << d << endl; } // function overloading
        int getlen() const { return *len; } // 不能在const对象上调用非const成员函数
        int getold() const { return old; } // 不能在const对象上调用非const成员函数

        OverLD(){                // non-parameter constructor
            cout << "call the non-parameter constructor" << endl;
            this->len = new int; // since the class has pointer member,
        }                        // need to open up memory space
                                         
        
        explicit OverLD(int a, int len): old(a)      
        {
            this->len = new int;
            *(this->len) = len;

            cout << "call the constructor" << endl;

        }

        OverLD(const OverLD& o){ // copy constructor
            cout << "call the copy constructor" << endl;
            old = o.old;
            len = new int;
            *len = *(o.len);
        }

        OverLD(OverLD && o): old(o.old), len(o.len){ // move constructor
            cout << "call the move constructor" << endl;
            o.len = nullptr;
        }

        OverLD& operator=(const OverLD& other) noexcept{ // copy assignment operator
            cout << "call the copy assignment operator" << endl;
            if(this != &other){
                delete this->len; // release the original memory
                this->len = new int;
                *(this->len) = *(other.len);
                this->old = other.old;
            }
            return *this;
        }

        OverLD operator+(const OverLD& o){ // overloading operator as the member function
            cout << "call the member function which overloads the operator +" << endl;
            OverLD operator_result;
            operator_result.old = this->old + o.old;
            *(operator_result.len) = *(this->len) + *(o.len);
            return operator_result; // 因为编译器NRVO优化，返回局部对象时没有调用移动构造函数
        }

        virtual ~OverLD(){
            delete len;
            len = nullptr;
            cout << R"((delete the OverLD object! ))" << endl;
        }

        friend OverLD operator+(const OverLD& o, const OverLD& ol); // declare friend function
        friend OverLD operator+(const OverLD& o, int num); // declare friend function
        int aaa;

};


OverLD operator+(const OverLD& o, const OverLD& ol){ // overloading operator
    cout << "call the friend function which overloads the operator +" << endl;
    OverLD operator_result;
    operator_result.setold(o.getold() + ol.getold());
    operator_result.setlen(o.getlen() + ol.getlen());
    
    return operator_result;
}

OverLD operator+(const OverLD& o, int num){ // operator overloading can overload
    OverLD overld(o); // use copy constructor to initialize overld
    overld.setold(overld.getold() + num);
    overld.setlen(overld.getlen() + num);

    return overld;
}



void overloadingTest(){
    OverLD o1 = OverLD(1,2); // 显式调用构造函数
    OverLD o2 = OverLD(3,4); // 显式调用构造函数

    cout << "o3" << endl;
    OverLD o3 = o1 + o2; // 调用重载的+运算符的成员函数
    o3 = o3 + o1; // 调用重载的+运算符的成员函数, 主要是注意操作符=的重写

    cout << "o4" << endl;
    OverLD o4 = o1 + 4;

    cin.get();

    cout << "o3.getlen() = " << o3.getlen() << endl; // 6
    cout << "o4.getold() = " << o4.getold() << endl; // 5
}






/*=======================C++ polymorphisms========================*/
class Shape{
    protected:
        double width;
        double height;
        int *ptr;
    
    public:
        virtual double area() = 0; // 纯虚函数，没有函数体，必须在派生类中实现
        // In C++, once you have a pure virtual member function, 
        // your class becomes an abstract class and you cannot create any objects from it.

        void setwidth(double w){ width = w; }
        void setheight(double h){ height = h; }
        double getheight() const { return height; }
        double getwidth() const { return width; }
        int getlen() const { return *ptr; }
        Shape(): width(), height(), ptr(nullptr){ ptr = new int; *ptr = 0;} // 如果不写ptr()，指针成员将保持未初始化状态
        Shape(double w, double h, int len): width(w), height(h){
            ptr = new int;
            *ptr = len;
        }
        Shape(const Shape& s){ // copy constructor
            cout << "Call the Shape copy constructor" << endl;
            ptr = new int;
            *ptr = *(s.ptr);
            
            width = s.width;
            height = s.height;
        }
        virtual ~Shape(){ // if base class and it's derived class has dynamic memory allocating, 
                          // the base class destructor function is must to be virtual
            delete ptr;
            ptr = nullptr;
            cout << R"((delete the Shape object! ))" << endl;
        }
        
};


class Rectangle : virtual public Shape{
    public:
        Rectangle(): Shape(){}
        Rectangle(double w, double h, int len): Shape(w,h,len){}
        Rectangle(const Rectangle& s){ // copy constructor
            cout << "Call the Rectangle copy constructor" << endl;
            ptr = new int;
            *ptr = *(s.ptr);
            
            width = s.width;
            height = s.height;
        }
        virtual ~Rectangle(){
            delete ptr;
            ptr = nullptr;
            cout << R"((delete the Rectangle object! ))" << endl;
        }

        // virtual overloading
        double area(){
            return width * height;
        }

        Rectangle operator+(const Rectangle& s){
            /*
            在Triangle类的成员函数中，可以访问: 
                当前对象(this)的protected成员和private成员
                同类型其他对象的protected成员
            所以可以直接用s.width和s.height来访问另一个Triangle对象的protected成员
            这是因为protected成员在“同一个类”

            注意: 访问权限是相较于“类”而不是“对象”来说的, 所以protected可以被“同类”的其他对象访问
            */
            Rectangle sss;
            sss.width = this->width + s.width; 
            sss.height = this->height + s.height;
            *(sss.ptr) = *(this->ptr) + *(s.ptr);

            return sss;
        }
};


class Triangle : virtual public Shape{
    public:
        Triangle(): Shape(){}
        Triangle(double w, double h, int len): Shape(w,h,len){}
        Triangle(const Triangle& s){ // copy constructor
            cout << "Call the Triangle copy constructor" << endl;
            ptr = new int;
            *ptr = *(s.ptr);
            
            width = s.width;
            height = s.height;
        }
        virtual ~Triangle(){
            delete ptr;
            ptr = nullptr;
            cout << R"((delete the Triangle object! ))" << endl;
        }

        // 子类通常需要重写操作符重载函数，以确保操作符在子类对象上表现出预期的行为
        Triangle operator+(const Triangle& s){
            Triangle sss;
            sss.width = this->width + s.width;
            sss.height = this->height + s.height;
            *(sss.ptr) = *(this->ptr) + *(s.ptr);

            return sss;
        }
        // virtual overloading, and it's not pure
        double area(){
            return (width * height) / 2;
        }
};


class finalClass final : public Shape {
    public:
        double area() final{
            cout << "this class can't be inherit \n" 
            "and the area() can't be reloading no longer" << endl;
            return 0;
        }
};



void polymorphismsTest(){
    Shape *shape;
    Rectangle ra(5,5,1);
    Triangle ta(6,6,2);

    cout << "ra.getheight() = " << ra.getheight() << endl; // 调用基类Shape的成员函数
    cout << "ta.getheight() = " << ta.getheight() << endl; // 调用基类Shape的成员函数

    cout << "ra.area() = " << ra.area() << endl; // 调用 Rectangle area()
    cout << "ta.area() = " << ta.area() << endl; // 调用 Triangle area()

    shape = &ra;  // virtual function is be used in the situation that 
                  // using the parent pointer point to derived class
    cout << "shape(ra)->area() = " << shape->area() << endl; // call the Rectangle area()
    shape = &ta;
    cout << "shape(ta)->area() = " << shape->area() << endl; // call the Triangle area()

    finalClass fc;
    fc.area();

}



int main(){
/*=======================classBoxTest========================*/
    cout << "<===========classBoxTest===========>" << endl;
    void classBoxTest();
    classBoxTest();
    
    cout << endl;
    void classSmallBoxTest();
    classSmallBoxTest();


/*=======================friend function and friend class========================*/
    cout << "<===========friend function and friend class===========>" << endl; 
    void friendofBoxTest();
    friendofBoxTest();


/*=======================pointer of the class========================*/
    cout << "<===========pointer of the class===========>" << endl; 
    void PtrBoxTest();
    PtrBoxTest();

    cout << Box::objectcount << endl;


/*=======================static member variables========================*/
    cout << "<===========static member variables===========>" << endl;
    void staticMemberTest();
    staticMemberTest();


/*=======================C++ inherit========================*/
    cout << "<===========C++ inherit===========>" << endl;
    void inheritTest();
    inheritTest();


/*=======================C++ operator and function overloading========================*/
    cout << "<===========C++ operator and function overloading===========>" << endl;
    void overloadingTest();
    overloadingTest();


/*=======================C++ polymorphisms========================*/
    cout << "<===========C++ polymorphisms===========>" << endl;
    void polymorphismsTest();
    polymorphismsTest();



    return 0;
}