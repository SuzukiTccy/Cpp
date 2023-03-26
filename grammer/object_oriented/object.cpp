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
        static int getObjectcount(){ return objectcount; }


        // Member function declaration and definition
        void setlength(double l){ length = l; } // inline function
        void setbreadth(double b){ breadth = b; }
        void setheight(double h){ height = h; }
        double getVolume(){
            return length * breadth * height; 
        }
        int getptr(){ return *ptr; }
        double getlength(){ return length; }
        Box(double l, double b, double h, int len): length(l), breadth(b), height(h)
        {
            ptr = new int;
            *ptr = len; // if the formal parameters name is same to the member variables,
                        // then use the 'this' pointer
            objectcount++;
            cout << "The object is be created!" << endl;
        }

        Box(const Box &bbox){ // if the class have the pointer variables, u must to difine a copy constructor
            cout << R"((Call the copy constructor))" <<endl;
            ptr = new int;
            *ptr = *bbox.ptr;

            length = bbox.length;   // if build a copy constructor function, need to define all the member variables
            breadth = bbox.breadth; // or they will be defined as the random values.
            height = bbox.height;
        }

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

double getBoxVolume(Box &b){  // when call getBoxVolume, it will call the copy constructor implicitly to create a temp object,
                             // and when haved called this function, it will call the destructor, 
                             // cause it need to delete the temp object
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
    private:
        double smallLength;
        double smallBreath;
    public:
        void setsmallLength(double l){ length = l; }
        // constructor can't be inherited
        smallBox(double l, double b, double h, int len, double sb): 
        Box(l, b, h, len), smallLength(1.33), smallBreath(sb)
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
    smallBox box1(3.00, 4.00, 5.00, 2, 6.00);
    box1.setsmallLength(1.00);
    box1.setbreadth(2.00);
    box1.setheight(3.00);

    double volume = ::getBoxVolume(box1); // global function getBoxVolume()
    cout << "volume = " << volume << endl;
    cout << "box1.getptr() = " << box1.getptr() << endl; // child class can call the parent class non-private member function
    cout << "box1.Box::getlength() = " << box1.Box::getlength() << endl; // can use :: to access the parent member, 
}                                                                        // when the parent class has the same name members to the child






/*=======================C++ inherit========================*/
class tiny: virtual public Box{
    private:
        double tinyy;
    public:
        tiny(double l, double b, double h, int len): Box(l, b, h, len){}
        ~tiny(){
            cout << R"((delete the tiny object! ))" << endl;
        }

};


class tinyBox : public smallBox, public tiny{ // multiple inherit, unrecommend
    private:
        double tinybreath;
        double tinyheight;
        double tinylength;

    public:
        tinyBox(double l, double b, double h, int len, 
                double sb, double tb, double th, double tl):
        Box(l, b, h, len),
        smallBox(l, b, h, len, sb), 
        tiny(l, b, h, len), 
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
    cout << "tb.getlength() = " << tb.getlength() << endl;

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
        int getlen(){ return *len; }
        int getold(){ return old; }
        OverLD(){ this->len = new int; } // non-parameter constructor
                                         // since the class has pointer member,
                                         // need to open up memory space
        OverLD(int a, int len): old(a)      
        {
            this->len = new int;
            *(this->len) = len;

            cout << "call the constructor" << endl;

        }
        virtual ~OverLD(){
            delete len;
            len = nullptr;
            cout << R"((delete the OverLD object! ))" << endl;
        }
        OverLD(const OverLD& o){
            old = o.old;
            len = new int;
            *len = *(o.len);
            cout << "call the copy constructor" << endl;
        }

        OverLD(OverLD && o): old(o.old), len(o.len){ // move constructor
            o.len = nullptr;
            cout << "call the move constructor" << endl;
        }

        OverLD operator+(const OverLD& o){ // overloading operator as the member function
            OverLD overld;
            overld.old = this->old + o.old;
            *(overld.len) = *(this->len) + *(o.len);
            return overld;
        }
        friend OverLD operator+(OverLD& o, OverLD& ol); // declare friend function
        friend OverLD operator+(OverLD& o, int num); // declare friend function
        int aaa;


};


OverLD operator+(OverLD& o, OverLD& ol){ // overloading operator as the non-member function
    OverLD overld;
    overld.setold(o.getold() + ol.getold());
    overld.setlen(o.getlen() + ol.getlen());
    
    return overld;
}

OverLD operator+(OverLD& o, int num){ // operator overloading can overload
    OverLD overld(o);
    overld.setold(overld.getold() + num);
    overld.setlen(overld.getlen() + num);

    return overld;

}



void overloadingTest(){
    OverLD o1 = OverLD(1,2);
    OverLD o2 = OverLD(3,4);

    OverLD o3 = o1 + o2;
    OverLD o4 = o1 + 4;

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
        virtual double area() = 0;
        // In C++, once you have a pure virtual member function, 
        // your class becomes an abstract class and you cannot create any objects from it.

        void setwidth(double w){ width = w; }
        void setheight(double h){ height = h; }
        double getheight(){ return height; }
        double getwidth(){ return width; }
        int getlen(){ return *ptr; }
        Shape(): width(), height(), ptr(){ ptr = new int; }
        Shape(double w, double h, int len): width(w), height(h){
            ptr = new int;
            *ptr = len;
        }
        Shape(const Shape& s){
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


class Rectangle : public Shape{
    public:
        Rectangle(): Shape(){}
        Rectangle(double w, double h, int len): Shape(w,h,len){}
        Rectangle(const Rectangle& s){
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

        Rectangle operator+(const Rectangle& s){
            Rectangle sss;
            sss.width = this->width + s.width;
            sss.height = this->height + s.height;
            *(sss.ptr) = *(this->ptr) + *(s.ptr);

            return sss;
        }
        // virtual overloading, and it's not pure
        double area(){
            return width * height;
        }
};


class Triangle : public Shape{
    public:
        Triangle(): Shape(){}
        Triangle(double w, double h, int len): Shape(w,h,len){}
        Triangle(const Triangle& s){
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

    cout << "ra.getheight() = " << ra.getheight() << endl;
    cout << "ta.getheight() = " << ta.getheight() << endl;

    cout << "ra.area() = " << ra.area() << endl;
    cout << "ta.area() = " << ta.area() << endl;

    shape = &ra;  // virtual function is be used in the situation that using the parent pointer point to derived class
    cout << "shape(ra)->area() = " << shape->area() << endl;
    shape = &ta;
    cout << "shape(ta)->area() = " << shape->area() << endl;

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