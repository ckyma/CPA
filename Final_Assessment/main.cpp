/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on September 10, 2014, 2:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Q1
/*
class Class1 {
    char a;
protected:
    char b;
public:
    char c;
    Class1() { a='a'; b='b'; c='c'; }
};
class Class2 : public Class1 {
    char d; // error: ‘char Class2::d’ is private
public:
    void set() {            
        c = 'e';
        d = 'd';
    }
};
*/

// Q4
/*
class One {
public: float f;            
    One(float f) { this -> f = f; }
};
class Two {
public: float f;
    Two (One o) { this -> f = o.f; }
    // Two (One& o) { this -> f = o.f; } // same result here
    void foo() { cout << (int)f; }
};
*/

// Q6
/*
class X1 {
public: virtual void foo() = 0;
};
class X2 : public X1 {
public: virtual void foo() { cout << "X2"; }
};
class X3 : public X1 {
public: virtual void foo() { cout << "X3"; }
};
*/

// Q8
/*
class Sup {
public: virtual void out() { cout << "p"; }
};
class Sub : public Sup {
public: virtual void out() { cout << "b"; }
};
*/

// Q10
/*
int doit(int x) {
    return x << 1;
 }
*/

// Q12
/*
#define CALL(param) { if(param) cout << param++; }  // define function macros
*/

// Q15
/*
struct S
{
  char *p;
};
class C
{
  S s;
public:
  C() { s.p = new char; *s.p = 'A'; }
  void p() { cout << ++(*s.p); }
};
*/

// Q16
/*
class A
{
public: void out(){ cout << "A"; }
};
class B : public A
{
public: void out(){ cout << "B"; }
};
*/

// Q17
/*
using namespace std;
int calculate(int &val, int arg)
{
        val *= arg;
        return arg;
}
*/

// Q20
/*
class One
{
    char value;
public:
    One() { value = 'A'; }
    One(char v) : value(v) {}
    void set(char c) {this -> value = c; }
    void set() { this -> value = 'd'; }
    char get(){ return value; }
};
*/

// Q21
/*
class Alpha {
public: char out(){ return 'A'; }
};
class Beta : public Alpha {
public: virtual char out(){ return 'B'; }
};
class Gamma : public Beta {
public: char out(){ return 'G'; }    
};
*/

// Q22
/*
class Uno
{ public: void foo(){ cout << "0";}
          void bar(){ cout << "1";}
};
class Due : public Uno
{ public: void foo(){ cout << "2";}
          void bar(){ cout << "3";}
};
*/

// Q25
/*
class Uno {
public: int n;
    Uno() { n = 1; }
    Uno(int v) { n = v;}
};
class Due : public Uno {
public:
    int *arr;
    Due() : Uno() {
      arr = new int[n];
    }
    Due(int a) : Uno(a) {
      arr = new int[n];
    }
    ~Due() { delete arr; }
};
*/

// Q27
/*
class Uno {
public: int Int;
};
class Due : public Uno {
public: Due() { Int = 2;}
        Due(int x) { Int = x == 0 ? 2 : x - 2; }
};
*/

// Q28
/*
namespace OuterSpace
{
  int x = 1;
  int y = 2;
}
namespace InnerSpace
{
  float x = 3.0;
  float y = 4.0;
}
*/

// Q30
/*
class Uno {
public: char Char;
};
*/

// Q31
/*
char max(char x, char y) {
    if(x > y)
      return y;
    else
      return x;
}
*/

// Q35
/*
struct S {
    int  a;
    char b;
    struct {
        float a;
        int   b;
    } c;
};
*/

// Q40
/*
class Uno {
public: Uno() { cout << "X"; }
};
Uno foo(Uno d)
{
    Uno e = d;
    return e;
}
*/

// Q41
/*
class Uno {
public: ~Uno() { cout << "X"; }
};
void foo(Uno *d)
{
    Uno e;
    *d = e;
}
*/

// Q42
/*
int k = -1;
class Class
{
public: char *adr;
    Class() { adr = new char[k]; } // terminate called after throwing an instance of 'std::bad_alloc'
                                    // what():  std::bad_alloc
    ~Class() { delete [] adr; }
};
int fun(void)
{
    Class object;
    return 0.5f;
}
*/

// Q43
/*
struct Who
{
    string nick;
};
class She
{
    Who *who;
public:
    She() {
        who = new Who;
        who -> nick = "Jane";
    }
    string out (){
        return who -> nick;
    }
};
*/

// Q45
/*
int X = 5;
*/

// Q46
/*
int doit(int a, float b)
{
   return a / b;   
}
*/

// Q47
/*
class Uno {
protected: char y;
public:    char z;
};
 // insert code here
class Due : protected Uno 
// class Due : public Uno 
{
public:
void set() {
        y = 'a';  z = 'z';
}
void out() { cout << ++y << --z; }
};
*/

// Q50
class Uno {
    int val;
public: Uno(int x) { val = x; }
    int out() { return val; }
    void operator++(int var) {  // int var is not used
        val += val; // val = 2, so (val += val) == 4
    }
};
ostream &operator<<(ostream &o, Uno u)
{
    return o << u.out();
}


/*
 * 
 */
int main(int argc, char** argv) {
    
    // Q1: ed is wrong, Compilation fails is right
    /*
    Class2 a;
    a.set();
    // cout << a.c << a.d; // error: ‘char Class2::d’ is private
    cout << a.c << endl;
    cout << a.Class1::c << endl;    // object of the subclass has a member of the supclass
    */
    
    // Q2: 7531
    /*
    int i = 8;
    do {
        i--;
        cout << i--;
    }
    while(i);
    */
    
    // Q4: 3
    /*
    One o1(3.14);
    Two o2 = o1;
    o2.foo();
    */
    
    // Q5: Compilation fails
    /*
    const char c = '!';
    const char *p;
    p = &c;
    *p = '?'; // error: assignment of read-only location ‘* p’
    cout << *p;
    */
    
    // Q6: X3X2
    /*
    X1 *a = new X2(), *b = new X3();
    b->foo();
    a->foo();
    */
    
    // Q7: None of these
    /*
    float B = 32;
    { char B = '1'; cout << B; }
    { int B = 2; cout << B; }
    cout << B;
    */
    
    // Q8: bb
    /*
    Sub sub;
    Sup *sup;
    sup = &sub;
    sup->out();
    sub.out();
    */
    
    // Q10: 1
    /*
    int i;
    i = doit(1) || doit(0);
    cout << i << endl;;
    cout << doit(1) << endl;
    cout << doit(0) << endl;
    */
    
    // Q12: 12
    /*
    int i = 1;
    CALL(i);    // // define function macros
    cout << i;
    */
    
    // Q13: 0
    /*
    int a = 0;
    if (++a == 1) {
        cout << (a >> 1);
    } else {
        cout << (a);
    }
    */
    
    // Q15: B
    /*
    C *c = new C();
    c->p();
    */
    
    // Q16: AA
    /*
    A *a;
    a = new A();
    a -> out();
    a = new B();
    a -> out();
    */
    
    // Q17: 22
    /*
    int i = 1;
    int j = calculate(i,2);
    cout << i << j;
    */
    
    // Q20: -1
    /*
    One o1,*o2;
    o2 = new One('b');
    One *p;
    p = &o1;
    p -> set();
    p = o2;
    p -> set('c');
    cout << o2->get() - o1.get();
    */
    
    // Q21: AAA
    /*
    Alpha *a = new Alpha();
    Alpha *b = new Beta();
    Alpha *c = new Gamma();
    cout << (a->out()) << (b->out()) << (c->out());
    */
    
    // Q22: d.Uno::foo();
    /*
    Due d;
    // insert code here
    d.Uno::foo();
    d.bar();
    */
    
    // Q24: Compilation fails
    /*
    const PI = 3.14;
    const PI2 = PI * PI;
    cout << PI2;
    */
    
    // Q25: 3
    /*
    Due d(2);
    Due e;  
    cout << d.n + e.n;
    */
    
    // Q27: 0
    /*
    Due d,d2(0);
    cout << d.Int - d2.Int;
    */
    
    // Q28: Compilation fails is wrong, 3 4 is right
    /*
    { using namespace InnerSpace;
        cout << x << " ";
    }{
        // int y = 0; // if added, line "using InnerSpace::y;" got error: ‘y’ is already declared in this scope
        using namespace OuterSpace; 
        // cout << y << endl;
        // using namespace InnerSpace;  // no error, just override
        using InnerSpace::y;    // no error, just override
        cout << y << endl;
        // cout << x << endl;  // 1
    }
    */
    
    // Q30: 5
    /*
    int swtch;
    Uno u;
    u.Char = '5';
    cin >> swtch;
    try
    {
        switch (swtch)
        {
        case 3:  throw 1;
        case 2:  throw 3.f;
        case 1:  throw u;
        }
    }
    catch (int e)
    { cout << e; }
    catch (Uno e)
    { cout << e.Char; }
    catch (...)
    { cout << "?"; }
    */
    
    // Q31: a
    /*
    char chr = max('a', 'z');
    cout << chr;
    */
    
    // Q35: 34
    /*
    S s = { 1, 2, 3, 4 };
    cout << s.c.a << s.c.b;
    */
    
    // Q38: 9
    /*
    int cnt = 10;
    do {
        cnt--;
        if (cnt % 3 == 2)
            break;
        cout << cnt;
    }
    while(cnt);
    */
    
    // Q39: c
    /*
    char *abc;
    abc = new char[26];
    for(int i = 0; i < 26; i++) 
        abc[i] = 'a' + i;            
    cout << *(abc + 2);
    */
    
    // Q40: X
    /*
    Uno u;
    foo(u);
    */
    
    // Q41: XX
    /*
    Uno *u = new Uno;
    foo(u);
    delete u;    // If remove, no destructor is called
    // throw exception();   // no destructor is called
    // Uno v;  // destructor is called automatically
    // throw exception();  // no destructor is called for v
    */
    
    // Q42: Runtime error
    /*
    fun();
    */
    
    // Q43: JaneJane
    /*
    She they[2];
    for(int i = 0; i < 2; i++)
        cout << they[i].out();
    */
    
    // Q44: 5
    /*
    int i = 0;
    for(; i < 5; i++);
    cout << i;
    */
    
    // Q45: 6
    /*
    cout << "HI!";
    if(X-- > 0)
        main(argc, argv);
    */
    
    // Q46: 0:1
    /*
    float x = doit(1.5f, 2l);
    cout << x << ":" << doit(1, 1.f);
    */
    
    // Q47: Multiple choices, class Due : public Uno is not the only one, class Due : protected Uno is also right
    /*
    Due b;
    b.set();
    b.out();
    */
    
    // Q48 : e
    /*
    int i = 2;
    float f = 1.4;
    char c = 'a';
    bool b = true;
    c += i + f + b;
    cout << c;
    */
    
    // Q50: 3 is wrong, 4 is right
    Uno i(2);
    i++;
    cout << i;
    
    return 0;
}

