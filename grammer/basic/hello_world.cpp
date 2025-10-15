#include <iostream>
#include<cstring>
using namespace std;

extern int e;

/*=======================debug help func========================*/
void printsubtitle(string subtitle){
    string separator1 = "<=====";
    string separator2 = "=====>\n";
    cout << separator1 + subtitle + separator2 << endl;
};

void pause(){
    cout << "Press any key to continue...";
    cin.get();
};

/*=======================enumeration========================*/
enum COLOR{
    red,
    green=5,
    blue,
} a;

struct Demo
{
    char name[10000];
    int count;
};

struct BOOKS{
    char title[50];
    char author[50];
    int ID;
};


COLOR b=green;
COLOR c;
void enumeration(){
    cout << "========enumeration type========" << endl;
    cout << "a:" << a << endl; // 0
    c = blue;
    cout << "b:" << b << endl; // 5
    cout << "c:" << c << endl; // 6
};



/*=======================#define, typedef, using========================*/
#define CR COLOR
#undef CR // Undefine the macro
typedef COLOR color; // 用于定义已有类型的别名，常用于复杂结构体声明时的简化
using color = COLOR; // firstly

/*
typedef struct example {
} e;
*/

/*=======================global and static========================*/
int count = 1;
int fun()
{
    static int scount = 10; // 在第一次进入这个函数的时候，变量 scount 被初始化为 10 并接着自减 1，
                            // 以后每次进入该函数，count 的值是上一次函数运行之后的值
    return scount--;        // 就不会被再次初始化了，仅进行自减 1 的操作；在 static 发明前，要达到同样的功能，则只能使用全局变量
};

static int ccount; // 声明了一个只能在当前文件访问的全局变量
static void ff(); // 声明了一个只能在当前文件访问的函数（内部函数）

void ff(){}

void printcolor(color clr = red, string str="hello"){
    string head = "";
    string tail = "";
    string display = str;
    switch(clr){
        case red:{
            head="\033[31m";
            tail="\033[0m";
            display=head+str+tail;
            break;
        }
        case green:{
            head="\033[32m";
            tail="\033[0m";
            display=head+str+tail;
            break;
        }
        case blue:{
            head="\033[34m";
            tail="\033[0m";
            display=head+str+tail;
            break;
        }
    }
    cout << display << endl;
};


int main(){
    void printsubtitle(string subtitle);
/*=======================enumeration demonstration========================*/
    enumeration();


/*=======================Conditional compilation demonstration========================*/
    #if 0
        cout << "Test version" << endl;
    #else
        cout << "<=======================Conditional compilation demonstration=======================>" << endl;
        cout << "Release version" << endl;
    #endif


/*=======================static variable demonstration========================*/
    cout << "<=======================static variable demonstration=======================>" << endl;
    for(int i = 1; i <= 5; i++){
        cout << "scount:" << fun() << endl;
    }


/*=======================explicit(显式) constructor demonstration========================*/
    class Test{
    public:
        explicit Test(int n){
            num=n;
        } //explicit constructor, 
    private:
        int num;
    };

    Test t1(12);
    // Test t2 = 12; // Error, because when declare the explicit constructor, 
                     // then the constructor must be called explicitly


/*=======================C++ operator, %, &, <<, >>========================*/
    cout << "\n<=======================C++ operator, %和&=======================>" << endl;
    int a,b,c,aop;
    a=53;
    b=a%8; // 53%8=5
    c=a&7; // 53&7=5
    aop=4;
    cout << "b=" << b << endl; // 53%8=5
    cout << "c=" << c << endl; // 53&7=5
    cout << "b is equal with c\n" << endl;
    cout << "%2 is equal with &1, %4 is equal with &3, %32 is equal with &31, and so on" << endl;
    cout << "There is a two- to three-fold efficiency gain\n" << endl;
    cout << "12^12 = " << (12 ^ 12) << endl; // ^can be used to compare two number

    cout << "aop << 1 = " << (aop << 1) << endl; // << can be used to move the bits of a number
    cout << "aop >> 1 = " << (aop >> 1) << endl; // >> can be used to move the bits of a number


/*=======================loop========================*/
    cout << "\n<=======================for loop=======================>" << endl;
    for(int i = 0; i <= 10; i++){
        cout << "i = " << i << endl;
    }

    cout << "\n<========for loop based on the range========>" << endl;
    int my_array[5] = {1,3,5,7,9};
    for(const int &i : my_array){
        cout << "i = " << i << endl;
    }

    cout << "\n<========while loop========>" << endl;
    int i = 0;
    while(i < 10){
        cout << "i = " << i << endl;
        i++;
    }


/*=======================switch========================*/
    cout << "\n<=======================switch=======================>" << endl;
    color cl=red;
    switch(cl){
        case 0:
            cout << "cl=red" << endl;
            break;
        case 5:
            cout << "cl=green" << endl;
            break;
        case 6:
            cout << "cl=blue" << endl;
            break;
        default:
            cout << "cl is other color" << endl;
    }

    void printcolor(color clr, string str);
    printcolor(cl, "helloworld!");
    printcolor(green, "helloworld!");
    printcolor(blue, "helloworld!");


/*=======================lambda expression========================*/

    cout << "\n<=======================lambda expression=======================>" << endl;
    // define an simple lambda expression
    auto basicLambda = [] { cout << "Hello, world!" << endl; };
    basicLambda();   // output：Hello, world!

    // indicates the return type
    auto add = [](int a, int b) -> int { return a + b; };
    // automatic infer the return type
    auto multiply = [](int a, int b) { return a * b; };

    int sum = add(2, 5);   // output：7
    int product = multiply(2, 5);  // output：10
    cout << "sum = " << sum << endl;
    cout << "product = " << product << endl;

    // lambda capture，it can capture the x which is defined in lambda_exp()，which call it Closure instance (A function that can use variables defined within other functions)
    void lambda_exp(), lambda_exp2(), lambda_exp3(), lambda_exp4();
    lambda_exp();
    lambda_exp2();
    lambda_exp3();
    lambda_exp4();


/*=======================random numbers========================*/
    cout << "\n<=======================random numbers=======================>" << endl;
    int get_rand(int a, int b), get_random(int a, int b);
    cout << get_rand(0, 100) << endl; // pesudo-random number
    cout << get_random(0, 100) << endl; // true-random number


/*=======================array========================*/
    cout << "\n<=======================array=======================>" << endl;
    // 1-dimension array definition
    int array[10] = {1,2,3,4,5,6};
    auto print_array = [array]{
        for(int i = 0; i<10 ; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    };
    cout << "array: ";
    print_array();

    // 2-dimension array definition
    int array_2[3][3] = {
        {1,2,3},
        {3,2,1},
        {1,2,3},
    };

    // array pointer
    int *arr;
    arr = array; // the first address of array
    cout << "array[5] = " << "*(arr+5) = " << *(arr+5) << endl;  // 6
    cout << "array[5] = " << "*(array+5) = " << *(array+5) << endl;  // 6
    int *array_pp0, *array_pp1;
    int* ppp[2] = {array_pp0, array_pp1}; // 指针数组

    // type_char array address
    char name[] = {"Zara Ali"};
    cout << "name = " << name << endl; // output: Zara Ali
    cout << "&name = "  << &name << endl; // output: the first address of string
    cout << "&name[1] = "  << &name[1] << endl; // output: ara Ali
    cout << "(void *)&name[1] = "  << (void *)&name[1] << endl; //由于&name[1]的类型是char*,直接输出会是字符串，
                                      //所以需要强转成其他类型才能输出地址
    cout << "name[0] = "  << name[0] << endl; // Z


    // Pass the array to the function, array as the argument of function, 会改变数组的值
    void array_f1(int *array);
    void array_f2(int array[10]); // the size is known
    void array_f3(int array[]); // the size is unknown

    int *getrandom_array(void); // make it clear to compiler that it is an empty argument list function
    // int *p = new int(); // this dynamically allocates an integer-sized block of memory on the heap 
    //                     // and returns a pointer to the first byte of that block. 
                           // This causes a memory leak, as the previously allocated block of memory is no longer accessible and cannot be freed,
                           // because next line of code the p is overwritted by the first address of static array r[] returned by getrandom().
    int *p = getrandom_array(); // first call the getrandom_array(), then assign its return value to the pointer p.

    cout << "<=====*getrandom_array()=====>" << endl;
    for(int i = 0; i<10; i++){
        cout << "*(p+" << i << ") = " << *(p+i) << endl;
    }

    cout << endl;
    cout << "<=====*return_arr()=====>" << endl;
    int *return_arr(int a, int b, int SIZE); // int *p = new int[SIZE]
    p = return_arr(0, 100, 10);
    for(int i = 0; i < 10; i++){
        cout << "*(p+" << i << ") = " << *(p+1) << endl;
    }

    // delete p;
    p = nullptr;

/*=======================string========================*/
    #include <string>  
    cout << "\n<=======================string=======================>" << endl;
    // end by the '\0'
    char r[5] = {'a', 'b', 'c', 'd', '\0'};
    char rr[] = "abcd";

    cout << "r = " << r << endl; // abcd
    cout << "rr = " << rr << endl; // abcd
    cout << "sizeof(r) = " << sizeof(r) << endl; // 5
    cout << "sizeof(rr) = " << sizeof(rr) << endl; // 5
    cout << "strlen(r) = " << strlen(r) << endl; // 4
    cout << "strlen(rr) = " << strlen(rr) << endl; // 4

    cout << endl;

    #if 0
        string str;
        cout << "Please input a string: ";
        getline(cin, str);
        cout << "str[0] = " << str[0] << endl; // the first char of str
        cin.get();
    #endif
    


    #if 0
    char s[20];
    cout << "Please input a string: ";
    cin.getline(s, 10); // 只读取前9个字符，会自动在末尾添加'\0'
    cout << "s = " << s << endl;
    cout << "sizeof(s) = " << sizeof(s) << endl; // 20
    cout << "strlen(s) = " << strlen(s) << endl; // 9

    cin.get();
    #endif

    // string literal

    // raw string
    cout << u8R"((UTF-8) not to explain Escape symbol \n)" << endl;



/*=======================pointer========================*/
    cout << endl << endl;
    cout << "<=======================pointer=======================>" << endl;
     
    // NULL pointer
    printsubtitle("NULL pointer");
    int *pp = nullptr;
    cout << "pp = " << pp << endl; // pp = 0x0

    // use pointer as array, can create a dynamic array, but no suggestion
    cout << endl << endl;
    int *t = new int();
    *t = 1;
    *(t+1)=2; // The +1 is attempting to access memory that is not allocated for t, which can result in undefined behavior.
    cout << "t[0] = " << t[0] << endl;
    cout << "t[1] = " << t[1] << endl;
    cout << "t[-1] = " << t[-1] << endl; // overflow the array can run, but is illegal
    delete t;
    t = nullptr; // when delete the dynamic pointer, must to point it to NULL

    // *t = 1; // Attempting to dereference a null pointer, as in the statement *t = 1;
    //         // results in undefined behavior and can cause the program to crash or exhibit unexpected behavior.
    t = new int(); // t 指针的重新使用
    *t = 1;
    delete t;
    t = nullptr;

    for(int i = 0; i<5; ++i){ //++i faster than i++
        cout << i << "\t";    // because ++i increments the value of i and returns the new value, that the code can proceed with the updated value,
    }                         // while i++ increments the value of i but returns the old value, that requires creating a copy of the pld value or retrieving it from memory
    cout << endl;             // 由于后缀运算符需要返回对象的副本，产生了额外的复制开销，因此++i的效率通常高于i++ 

    // int pointer array
    cout << endl << endl;
    printsubtitle("int pointer array");
    int *ptr[3];
    int ii[3] = {10, 11, 12};
    for(int i = 0; i < 3; ++i){
        ptr[i] = &ii[i];  // the every element in ptr[3] is store the address of the element in ii[3]
        cout << "*ptr[i] = " << *ptr[i] << endl;
    }

    // char pointer array, different from int
    cout << endl << endl;
    printsubtitle("char pointer array");
    const char *ptrst[3] = {"abc", "cde", "efg"}; // 字符串常量数组，每个元素都是一个指向字符的指针，指向一个字符串常量
    for(int i = 0; i < 3; ++i){
        cout << "the value of ptrst[i] = " << ptrst[i] << endl; // the value of ptrst[0] = abc
        cout << "the first value of ptrst[" << i << "] = " << *ptrst[i] << endl; // the first value of *ptrst[0] = a
        cout << "*(ptrst[i] + 1) = " << *(ptrst[i] + 1) << endl; // the first value of *(ptrst[0]+1) = b
    }

    // const int *p == int const *p, define a pointer p to an integer value that cannot be modified through the pointer.
    cout << endl << endl;
    printsubtitle("const int *p and int const *p");
    int sseee = 1;
    const int *pc1 = &sseee;
    int const *pc2;
    int ssee2 = 2;
    pc1 = &ssee2;
    // *pc1 = 2; is illegal, because the pointer just can point another address, but can not change the int which it point.
    cout << "*pc1 = " << *pc1 << endl; // 2
    cout << "pc1 = " << pc1 << endl;


    // int * const p, the pointer address can't change, but the int it point to can change, and must be initialized
    cout << endl << endl;
    printsubtitle("int * const p");
    int constp = 1;
    int * const cp = &constp;
    constp = 2;
    cout << "*cp = " << *cp << endl; // 2
    cout << "cp = " << cp << endl;
    *cp = 3; // modifies the value of constp to 3
    cout << "constp = " << constp << endl;
    cout << "*cp = " << *cp << endl; // 3
    cout << "cp = " << cp << endl; // the address of cp is not change

    // cp = &ssee2; Error, cannot change the value of cp


    // array pointer, can point to a mult-dimension
    cout << endl << endl;
    printsubtitle("array pointer");
    int app[2][2] = {
        {1,2},
        {3,4},
    };

    int (*ap)[2] = app; // means that ap is a pointer to an array of size 2 containing integers.
    for(int i = 0; i < 2; ++i){
        cout << "ap + " << i << " = " << ap + i << endl;  // ap+i is equal to &app[i]
        cout << "&app[" << i << "] = " << &app[i] << endl;
        cout << "*(ap + " << i << ") = " << *(ap + i) << endl; // *(ap+i) is equal to &app[i], 因为*ap的值本身就是一个指向数组的指针，所以*(ap+i)就是app[i]的地址
        cout << "*(*ap + " << i << ") = " << *(*ap + i) << endl; // *(*ap+i) = app[i][0]
        cout << "**(ap + " << i << ") = " << **(ap + i) << endl; // **(ap+i) = app[i][0];
        cout << endl;
        for(int j = 0; j < 2; ++j){
            cout << "app[i][j] = " << app[i][j] << endl;
            cout << "*(*(ap + " << i << ") +" << j << ") = " << *(*(ap + i) + j) << endl;
            cout << endl;
        }
    }

    // multilevel pointer
    cout << endl << endl;
    printsubtitle("mutilevel pointer");
    int var = 100;
    int *mptr = &var; // mptr = &var
    int **pmptr = &mptr; // pmptr = &mptr
    cout << "&var = " << &var << endl;
    cout << "mptr = " << mptr << endl;
    cout << "*pmptr = " << *pmptr << endl; // *pmptr = mptr = &var
    cout << endl;
    cout << "&mptr = " << &mptr << endl;
    cout << "pmptr = " << pmptr << endl;
    cout << "**pmptr = " << **pmptr << endl; // **pmptr = *mptr = var

    cout << endl;
    **pmptr = 120;
    cout << "var = " << var << endl; // var = 120
    int getp(int *);
    getp(&var);

    //-------null pointer-------//
    int *p4 = nullptr;
    //printf("%d",*p4); //Error，should judge whether it is an nullptr before use a pointor

    //-------wild pointer (dangling pointer)-------//
    int *p5 = new int(5);
    delete p5;
    p5 = nullptr; // There must be this step
    // printf("%d",*p5);  // hide bug，after deleting a pointer, it is necessary to set it to NULL, 
                          // otherwise the pointer may point to an uncontrollable location, which can cause the system to crash during runtime.



    //-------pointer memory leak------//
    cout << endl;
    printsubtitle("pointer memory leak");
    int *p6 = new int(6);
    cout << "*p6 = " << *p6 << endl;
    // delete p6;
    p6 = new int(7); // The block of memory that p6 originally pointed to has not yet been freed, and p6 points elsewhere.
                     // Originally, the new memory cannot be accessed and cannot be deleted, causing a memory leak.

    int *p7 = new int[10];
    delete [] p7; // new[] and delete[]


    // *p1 = 0 indicate the pointer don't point any object, but can't assign int() to the pointer
    int aa = 0;
    int *p12 = 0;   //right
    // int *p12 = aa;   //error


    typedef string * pstring; 
    // const pstring cstr == pstring const cstr == string * const cstr


    // function pointer
    cout << endl;
    printsubtitle("function pointer");
    int (*fp)(int);
    int ff(int);
    fp = ff;
    cout << "(*fp)(5) = " << (*fp)(5) << endl;

    typedef int (*fp1)(int);
    fp1 _fp = ff;
    cout << "_fp(5) = " << _fp(5) << endl;


    const char *test(void);
    const char * (*rrr)(void) = test;
    cout << "rrr() = " << rrr() << endl;


/*=======================reference========================*/
    cout << endl << endl;
    cout << "<=======================reference=======================>" << endl;

    // the difference about pointer and reference as the function parameter
    void func1(Demo);
    void func2(const Demo *);
    void func3(const Demo &);

    Demo d;
    Demo *dp = &d;
    Demo &dref = d;
    d.count = 10;

    func1(d);
    func2(dp);
    func3(dref);

    

/*=======================date and time========================*/
    cout << endl << endl;
    cout << "<=======================date and time=======================>" << endl;

    // get the current and UTC date and time
    void get_DateTime();
    printsubtitle("get_DataTime");
    get_DateTime();


    // get the current date and time by struct tm
    cout << endl;
    printsubtitle("get Data by struct tm");
    void getbytm();
    getbytm();


    // get the running time
    cout << endl;
    printsubtitle("get the running time");
    void getRTime();
    getRTime();


    // get the current date and time
    cout << endl;
    printsubtitle("get the current data and time");
    void Get_Current_Date();
    Get_Current_Date();



/*=======================I/O========================*/
    cout << endl << endl;
    cout << "<=======================I/O=======================>" << endl;
    // cerr, Non-buffered, it will definitely be printed on the screen, 
    // Even if memory have no space, it still can be print out
    char err[] = "The Error Message: ";
    cerr << err << endl;

    // clog, buffered, it will definitely be printed on the screen,
    cout << endl;
    char log[] = "The process is be completed !";
    clog << log << endl;



/*=======================struct========================*/
    cout << endl << endl;
    cout << "<=======================struct=======================>" << endl;

    BOOKS book;
    strcpy(book.title, "ABDSS"); // #include<cstring>
    strcpy(book.author, "ccy");
    book.ID = 1;
    void printbook(const BOOKS &);
    printbook(book);

    // struct initialization function
    cout << endl;
    void initstruct(void);
    initstruct();


    return 0;
} // main()



void initstruct(void){

    struct test{
        int data;
        string str;
        char c;
        // init function by myself
        void init(int a, string b, char c){
            this->data = a;
            this->str = b;
            this->c = c;
        }

        test(): data(), str(), c(){} // not have parameter Constructor
        test(int a, string b, char c): data(a), str(b), c(c){} // have parameter Constructor

    }t1, t2, t3;

    t1 = {1, "C", 'c'};
    t2 = test(2, "C#", '#');
    t3.init(3, "C++", '+');

    cout << "t1: " << t1.data << " " << t1.str << " " << t1.c << endl;
    cout << "t2: " << t2.data << " " << t2.str << " " << t2.c << endl;
    cout << "t3: " << t3.data << " " << t3.str << " " << t3.c << endl;



}



void printbook(const BOOKS &book){
    cout << "title: " << book.title << endl;
    cout << "author: " << book.author << endl;
    cout << "ID: " << book.ID << endl;
}




#include<ctime>
void get_DateTime(){

    time_t now = time(0); // The current date and time based on the current system

    char* dt = ctime(&now); // convert the 'now' into the form of a string

    cout << "本地日期和时间: " << dt << endl;

    tm *gmtm = gmtime(&now); // convert the 'now' into the form of a pointer
    dt = asctime(gmtm);
    cout << "UTC 日期和时间: " << dt << endl;

}


void getbytm(){

    time_t now = time(0); // The current date and time based on the current system

    cout << "1970 到目前的秒数: " << now << endl;

    tm* ltm = localtime(&now);

    // print the every part of struct tm
    cout << "年: "<< 1900 + ltm->tm_year << endl;
    cout << "月: "<< 1 + ltm->tm_mon<< endl;
    cout << "日: "<<  ltm->tm_mday << endl;
    cout << "时间: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

}


void getRTime(){
    
    clock_t start_t, end_t;
    double total_t;
    int i;

    start_t = clock();
    cout << "循环启动时间: " << start_t << endl;

    for(int i = 0; i < 1000000; ++i){

    }
    end_t = clock();
    cout << "循环结束时间: " << end_t << endl;

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    cout << "CPU占用时间: " << total_t << endl;

}


void Get_Current_Date()
{
    time_t nowtime = time(NULL); //获取日历时间   time_t time(time_t *t);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));   
    cout << tmp << endl;
}




void func1(Demo d){
    cout << "d.count = " << d.count << endl;
}

void func2(const Demo *d){ // use const modify formal parameters to limit function alter raw data
    if (d)
        cout << "d -> count = " << d->count << endl;
}

void func3(const Demo &d){  // use reference or pointer can improve efficiency, because it will not to create copies,
                            // while transfer value will
    cout << "d.count = " << d.count << endl;
}





int ff(int a){
    return a + 1;
}

const char *test(void){
    const char *r = "sbsss"; // char *r = "sbsss" is error, cause the string are the const value
    return r;
}


int getp(int *p){
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;  // why it can work? because when use the getp(int *), 
                                    // then a pointer will be create and point to the address which is &var,
                                    // the &p actually is the address of pointer above
                                    // 也就是说，传指针实际上还是会复制

    return 0;
}



#include<vector>
#include<algorithm>
void lambda_exp()
{
    int x = 10;
    auto add_x = [x](int a) mutable { x += 1; return a + x; };  // copy capture x
    auto multiply_x = [&x](int a) mutable { x += 5; return a * x; };  // reference capture x
    // 加了mutable关键字后，lambda表达式就可以修改按值捕获的变量了，可以认为x成为了add_x和multiply_x的局部变量
    // 多次调用会发现x的值在变化
    
    cout << "add_x(10) = " << add_x(10) << endl;  // 21
    cout << "add_x(10) = " << add_x(10) << endl;  // 22
    cout << "multiply_x(10) = " << multiply_x(10) << endl; // 150
    cout << "x = " << x << endl; // 15

};


void lambda_exp2()
{
    // output the count of element that can be divided by 2 in vector
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int even_count1 = 0;
    for_each(v.begin(), v.end(), [&even_count1](int a) {
        if(!(a & 1)){
            ++even_count1;
        }
    });

    cout << "even_count1 = " << even_count1 << endl; // 5

    int even_count2 = count_if(v.begin(), v.end(), [](int a) {return a & 1;});
    cout << "even_count2 = " << even_count2 << endl; // 5

};


void lambda_exp3()
{
    int i = 1024, j = 2048;
    
    cout << "&i = " << &i << endl;
    cout << "&j = " << &j << endl;


    auto fun1 = [=, &i]{
        cout << "&i = " << &i << endl;
        cout << "&j = " << &j << endl;
        cout << "the address of j has changed!" << endl; // j是值捕获，所以j的地址会改变
    };
    fun1();

};


void lambda_exp4(){
    class Test{
        public:
            void hello(){
                cout << "hello!" << endl;
            };
            void lambda(){
                auto fun = [this]{ //Capture the "this" pointer
                    this->hello(); // "this" pointer calls the class Test object
                };
                fun();
            };
    }t;
    t.lambda();
};





#include<cstdlib>
#include<ctime>
#include<random>
int get_rand(int a, int b){
    srand( (unsigned)time(NULL) );
    int r = (double)rand() / RAND_MAX * (b - a) + a;
    return r;
};

int get_random(int a, int b){
    random_device rd; // non-deterministic generator
    mt19937 gen(rd()); // to seed mersenne twister.
    uniform_int_distribution<> dist(a,b); // distribute results between a and b inclusive.
    return dist(gen);
};


int *getrandom_array(void){
    static int r[10];
    srand( (unsigned)time(NULL) ); // time(NULL) 返回time_t类型, 通常是长整型
    for(int i = 0; i<10; i++){     // srand需要传入一个unsigned类型的参数 
        r[i] = rand();
    }
    return r;
};

int *return_arr(int a, int b, int SIZE){
    int *r = new int[SIZE];
    srand( (unsigned)time(NULL) );
    for(int i = 0; i < SIZE; i++){
        r[i] = (double)rand() / RAND_MAX * (b - a) + a; // double转为int，将会被截断
    }
    return r;
};