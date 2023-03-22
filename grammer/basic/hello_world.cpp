#include <iostream>
#include<cstring>
using namespace std;

extern int e;

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
typedef COLOR color;
using color = COLOR; // firstly



/*=======================global and static========================*/
int count = 1;
int fun()
{
    static int scount = 10; // 在第一次进入这个函数的时候，变量 scount 被初始化为 10！并接着自减 1，以后每次进入该函数，count 的值是上一次函数运行之后的值
    return scount--;        // 就不会被再次初始化了，仅进行自减 1 的操作；在 static 发明前，要达到同样的功能，则只能使用全局变量
};

static int ccount; //声明了一个只能在当前文件访问的全局变量
static void ff(); //声明了一个只能在当前文件访问的函数（内部函数）


int main(){
/*=======================enumeration demonstration========================*/
    enumeration();


/*=======================Conditional compilation demonstration========================*/
    #if 0
        cout << "Test version" << endl;
    #else
        cout << "<========Conditional compilation demonstration========>" << endl;
        cout << "Release version" << endl;
    #endif


/*=======================static variable demonstration========================*/
    cout << "<========static variable demonstration========>" << endl;
    for(int i = 1; i <= 5; i++){
        cout << "scount:" << fun() <<endl;
    }


/*=======================explicit constructor demonstration========================*/
    class Test{
    public:
        explicit Test(int n){
            num=n;
        } //explicit constructor, 
    private:
        int num;
    };

    Test t1(12);
    // Test t2 = 12; // Error, because declare the explicit constructor, 
                     // then the constructor must be called explicitly


/*=======================C++ operator, %和&========================*/
    cout << "<========C++ operator, %和&========>" << endl;
    int a,b,c;
    a=53;
    b=a%8;
    c=a&7;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << "b is equal with c" <<endl;
    cout << "%2 is equal with &1, %4 is equal with &3, %32 is equal with &31, and so on" << endl;
    cout << "There is a two- to three-fold efficiency gain" << endl;
    cout << "12^12 = " << (12 ^ 12) << endl; // ^can be used to compare two number


/*=======================loop========================*/
    cout << "<========for loop========>" << endl;
    for(int i = 0; i <= 10; i++){
        cout << "i = " << i << endl;
    }

    cout << "<========for loop based on the range========>" << endl;
    int my_array[5] = {1,3,5,7,9};
    for(int &i : my_array){
        cout << "i = " << i << endl;
    }

    cout << "<========while loop========>" << endl;
    int i = 0;
    while(i < 10){
        cout << "i = " << i << endl;
        i++;
    }


/*=======================switch========================*/
    cout << "<========switch========>" << endl;
    color cl=red;
    switch(c){
        case 0:
            cout << "c=red" << endl;
            break;
        case 5:
            cout << "c=green" << endl;
            break;
        case 6:
            cout << "c=blue" << endl;
            break;
        default:
            cout << "c is other color" << endl;
    }

    void printcolor(string color="red", string str="hello");
    printcolor("red", "helloworld!");
    printcolor("green", "helloworld!");


/*=======================lambda expression========================*/

    cout << "<========lambda expression========>" << endl;
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
    cout << "<========random numbers========>" << endl;
    int get_rand(int a, int b), get_random(int a, int b);
    cout << get_rand(0, 100) << endl; // pesudo-random number
    cout << get_random(0, 100) << endl; // true-random number


/*=======================array========================*/
    cout << "<========array========>" << endl;
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
    arr = array;
    cout << "array[5] = " << "*(arr+5) = " << *(arr+5) << endl;
    cout << "array[5] = " << "*(array+5) = " << *(array+5) << endl;

    // type_char array address
    char name[] = {"Zara Ali"};
    cout << name << endl; // output: Zara Ali
    cout << &name << endl; // output: the first address of string
    cout << (void *)&name[1] << endl; //由于&name[1]的类型是char*,直接输出会是字符串，
                                      //所以需要强转成其他类型才能输出地址

    // Pass the array to the function, array as the argument of function
    void array_f1(int *array);
    void array_f2(int array[10]); // the size is known
    void array_f3(int array[]); // the size is unknown

    // return array
    int *getrandom(nullptr); //static int r[]
    int *p = new int();
    p = getrandom;
    for(int i = 0; i<10; i++){
        cout << "*(p+" << i << ") = " << *(p+i) << endl;
    }

    int *returnarr(int a, int b, int SIZE); // int *p = new int[SIZE]
    p = returnarr(0, 100, 10);
    for(int i = 0; i < 10; i++){
        cout << "*(p+" << i << ") = " << *(p+1) << endl;
    }

    delete p;
    p = NULL;

    #include <string>  
/*=======================字符串========================*/
    cout << "<=========字符串=========>" << endl;
    // end by the '\0'
    char r[5] = {'a', 'b', 'c', 'd', '\0'};
    char rr[] = "abcd";

    // getline()
    // string str;
    // getline(cin, str);
    // cout << "str[0] = " << str[0] << endl;

    // cin.getline()
    // char s[20];
    // cin.getline(s, 20);
    // cout << "s[20] = " << s << endl;

    // cin.get(), used to digest the Enter key
    // cin.get();

    // raw string
    cout << u8R"((UTF-8) not to explain Escape symbol(转义字符)\n)" << endl;



/*=======================pointer========================*/
    cout << endl << endl;
    cout << "<=========pointer=========>" << endl;
     
    // NULL pointer
    int *pp = nullptr;
    cout << "pp = " << pp << endl;

    // use pointer as array, can create a dynamic array, but no suggestion
    cout << endl << endl;
    int *t = new int();
    *t = 1;*(t+1)=2;
    cout << "t[0] = " << t[0] << endl;
    cout << "t[1] = " << t[1] << endl;
    cout << "t[-1] = " << t[-1] << endl; // overflow the array can run, but is illegal
    delete t;
    t = NULL; // when delete the dynamic pointer, must to point it to NULL
    *t = 1;
    cout << "sizeof(t) = " << sizeof(t) << endl;
    cout << "t = " << t << endl;

    for(int i = 0; i<5; ++i){ //++i faster than i++
        cout << i << "\t";
    }
    cout << endl;

    // int pointer array
    cout << endl << endl;
    int *ptr[3];
    int ii[3] = {10, 11, 12};
    for(int i = 0; i < 3; ++i){
        ptr[i] = &ii[i];
        cout << "*ptr[i] = " << *ptr[i] << endl;
    }

    // char pointer array, different from int
    cout << endl << endl;
    const char *ptrst[3] = {"abc", "cde", "efg"};
    for(int i = 0; i < 3; ++i){
        cout << "the value of ptrst[i] = " << ptrst[i] << endl;
        cout << "the first value of st[" << i << "] = " << *ptrst[i] << endl;
        cout << "*(ptrst[i] + 1) = " << *(ptrst[i] + 1) << endl;
    }

    // const int *p == int const *p, the address can change, but can't change the value it points to with this pointer
    int sseee = 1;
    const int *pc1 = &sseee;
    int const *pc2;
    int ssee2 = 2;
    pc1 = &ssee2;


    // int * const p, the pointer address can't change, but the int() it point to can change, and must be initialized
    cout << endl << endl;
    int constp = 1;
    int * const cp = &constp;
    constp = 2;
    cout << "*cp = " << *cp << endl;
    cout << "cp = " << cp << endl;
    *cp = 3;
    cout << "*cp = " << *cp << endl;
    cout << "cp = " << cp << endl; // the address of cp is not change

    // array pointer, can point to a mult-dimension
    cout << endl << endl;
    int app[2][2] = {
        {1,2},
        {3,4},
    };

    int (*ap)[2] = app; // must be initialized
    for(int i = 0; i < 2; ++i){
        cout << "ap + " << i << " = " << ap + i << endl;  // ap+i 是一维数组app[i]的地址，即ap+i==&app[i]==*(ap+i)
        cout << "&app[" << i << "] = " << &app[i] << endl;
        cout << "*(ap + " << i << ") = " << *(ap + i) << endl;

        cout << "**(ap + " << i << ") = " << **(ap + i) << endl; // 二级指针 **(ptr + i) = pp[i][0];
        cout << endl;
        for(int j = 0; j < 2; ++j){
            cout << "app[i][j] = " << app[i][j] << endl;
            cout << "*(*(ap + " << i << ") +" << j << ") = " << *(*(ap + i) + j) << endl;
            cout << endl;
        }
    }

    // multilevel pointer
    cout << endl << endl;
    int var = 100;
    int *mptr = &var; // mptr = &var
    int **pmptr = &mptr; // pmptr = &mptr
    cout << "&var = " << &var << endl;
    cout << "mptr = " << mptr << endl;
    cout << "*pmptr = " << *pmptr << endl;
    cout << endl;
    cout << "&mptr = " << &mptr << endl;
    cout << "pmptr = " << pmptr << endl;
    cout << "**pmptr = " << **pmptr << endl;

    cout << endl;
    **pmptr = 120;
    cout << "var = " << var << endl;
    int getp(int *);
    getp(&var);

    //-------空指针-------//
    int *p4 = NULL;
    //printf("%d",*p4); //运行Error，使用指针时必须先判断是否空指针

    //-------野指针（悬浮、迷途指针）-------//
    int *p5 = new int(5);
    delete p5;
    p5 = NULL; //一定要有这一步
    // printf("%d",*p5);  //隐藏bug，delete掉指针后一定要置0，不然指针指向位置不可控，运行中可导致系统挂掉

    //-------指针的内存泄漏-------//
    int *p6 = new int(6);
    cout << endl << "*p6 = " << *p6 << endl;
    // delete p6;
    p6 = new int(7); //p6原本指向的那块内存尚未释放，结果p6又指向了别处，原来new的内存无法访问，也无法delete了，造成memory leak

    int *p7 = new int[10];
    delete [] p7; // new[] and delete[]


    // *p1 = 0 indicate the pointer don't point any object, but can't assign int() to the pointer
    int aa = 0;
    int *p12 = 0;   //right
    // int *p12 = aa;   //error


    typedef string * pstring; 
    // const pstring cstr == pstring const cstr == string * const cstr


    // function pointer
    cout << endl << endl;
    int (*fp)(int);
    int ff(int);
    fp = ff;
    cout << "(*fp)(5) = " << (*fp)(5) << endl;

    typedef int (*fp1)(int);
    fp1 _fp = ff;
    cout << "_fp(5) = " << _fp(5) << endl;


    char * test(nullptr);
    const char *rrr = test;
    cout << "rrr = " << rrr << endl;


/*=======================reference========================*/
    cout << endl << endl;
    cout << "<=========reference=========>" << endl;

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
    cout << "<=========date and time=========>" << endl;

    // get the current and UTC date and time
    void get_DateTime();
    get_DateTime();


    // get the current date and time by struct tm
    cout << endl;
    void getbytm();
    getbytm();


    // get the running time
    cout << endl;
    void getRTime();
    getRTime();


    // get the current date and time
    cout << endl;
    void Get_Current_Date();
    Get_Current_Date();



/*=======================I/O========================*/
    cout << endl << endl;
    cout << "<=========I/O=========>" << endl;
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
    cout << "<=========struct=========>" << endl;

    BOOKS book;
    strcpy(book.title, "ABDSS"); // #include<cstring>
    strcpy(book.author, "ccy");
    book.ID = 1;
    void printbook(BOOKS);
    printbook(book);

    // struct initialization function
    cout << endl;
    void initstruct();
    initstruct();







    return 0;
} // main()



void initstruct(){

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



void printbook(BOOKS book){
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

    for(int i = 0; i < 100000; ++i){

    }
    end_t = clock();
    cout << "循环结束时间: " << end_t << endl;

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    cout << "CPU占用时间: " << total_t << endl;

}


void Get_Current_Date()
{
    time_t nowtime = time(NULL); //获取日历时间   
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

const char * test(){
    const char *r = "sbsss"; // char *r = "sbsss" is error, cause the string are the const value
    return r;
}


int getp(int *p){
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;  // why it can work? because when use the getp(int *), 
                                    // then a pointer will be create and point to the address which is &var,
                                    // the &p actually is the address of pointer above

    return 0;
}



#include<vector>
#include<algorithm>
void lambda_exp()
{
    int x = 10;
    auto add_x = [x](int a) mutable { x += 1; return a + x; };  // 复制捕捉x
    auto multiply_x = [&x](int a) mutable { x += 5; return a * x; };  // 引用捕捉x
    
    cout << "add_x(10) = " << add_x(10) << endl; 
    cout << "multiply_x(10) = " << multiply_x(10) << endl;
    cout << "x = " << x << endl;
    // 输出：20 100
};


void lambda_exp2()
{
    // 函数功能，输出vector中能整除2的个数
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int even_count1 = 0;
    for_each(v.begin(), v.end(), [&even_count1](int a) {
        if(!(a & 1)){
            ++even_count1;
        }
    });

    cout << "even_count1 = " << even_count1 << endl; 

    int even_count2 = count_if(v.begin(), v.end(), [](int a) {return a & 1;});
    cout << "even_count2 = " << even_count2 << endl; 

};


void lambda_exp3()
{
    int i = 1024, j = 2048;
    
    cout << "&i = " << &i << endl;
    cout << "&j = " << &j << endl;


    auto fun1 = [=, &i]{
        cout << "&i = " << &i << endl;
        cout << "&j = " << &j << endl;
        cout << "the address of j has changed!" << endl;
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


void printcolor(string color, string str){
    int clr;
    string head;
    string tail;
    string display;
    if(color=="red") clr=1;
    if(color=="green") clr=2;
    switch(clr){
        case 1:{
            head="\033[31m";
            tail="\033[0m";
            display=head+str+tail;
            break;
        }
        case 2:{
            head="\033[32m";
            tail="\033[0m";
            display=head+str+tail;
            break;
        }
        default:{
            display=str;
        }
    }
    cout << display << endl;
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


int *getrandom(){
    static int r[10];
    srand( (unsigned)time(NULL) );
    for(int i = 0; i<10; i++){
        r[i] = rand();
    }

    return r;
};

int *returnarr(int a, int b, int SIZE){
    int *r = new int[SIZE];
    srand( (unsigned)time(NULL) );
    for(int i = 0; i < SIZE; i++){
        r[i] = (double)rand() / RAND_MAX * (b - a) + a;
    }

    return r;
    delete[] r;
    r = NULL;
};