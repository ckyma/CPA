/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on September 9, 2014, 7:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Q4
/*
class One
{
    public:
        void out(){ cout<<"One";}
};
*/

// Q7
/*
void foo(int &parameter)
{
    parameter *= 2;
}
*/

// Q12
/*
class One {
public:
    //insert code here
    virtual void foo(){ cout << 1; } 
};
class Two : public One {
public:
        void foo(){ cout << 2; }
};
class Three : public Two {
public:
        void foo(){ cout << 3; }    
};
*/

// Q13
/*
namespace Space
{  char a = 'a', b = 'b';  }
int a = 1, b = 2;
*/

// Q15
/*
class foo {
    int p;
protected:
    int q;
public:
    int r;
};
class bar : public foo {
public:
    void assign() {
        p = q = r = 2; // error: 'int foo::p' is private
    }
    void out() { cout << q << r; }
};
*/

// Q19
/*
char c;
char* inc(char par1, int par2)
{
    c = par1 + par2;
    return &c;
}
*/

// Q20
/*
class a
{
public: virtual string whose()
        { return "mine"; }
};
class b
{
public: virtual string whose()
        { return "yours"; }
};
*/

// Q21
/*
class Alpha {
    int p;
protected:
    int q;
public:
    int r;
    Alpha():p(2),q(3),r(4) {}
};
class Beta : public Alpha {
    string s;
public:
    int y;
    void assign() {  y = 4; s = "f";   }
    void out() {
        // insert code here
        cout << char('a' + r) << s;
    }
};
*/

// Q22
/*
int sub(int x, int y)
{
    x -= y;
    return x;
}
*/

// Q25
/*
char fun(char *p)
{
   char c = *p;
   (*p)++;
   return c;
}
*/

// Q27
/*
class C1 {
friend class C2;
protected:  int y;
public:     int z;
private:    int x;
public:     C1() { x = y = z = 11; }
};
class C2 {
public: C1 a;
    C2 () { a.x = 22; };
    void foo() {
        cout << a.x << a.y << a.z;
    }
};
*/

// Q28
/*
int f(int a)
{
    return a + a;
}
*/

// Q29
/*
class Zero
{ public: void out(){ cout << 0;} };
class One : public Zero
{ public: void out(){ cout << 1;} };
class Two : public Zero
{ public: void out(){ cout << 2;} };
*/

// Q31
/*
string fun(string s)
{
    return s.substr(0,1)+s.substr(1,1)+s.substr(1,1)+s.substr(0,1);
}
*/

// Q35
/*
int var = -1;
int static Static(int i)
{
  static int y = 0;
  y += ++i;
  return y;
}
*/

// Q38
/*
class Class {
public:
   static char value;
   Class() { value++; };
   ~Class () { value++; };
   //insert code here
   void set(char c = 'd') { value = c; }
   void print() { cout << value;}
};
char Class::value = 'a';
*/

// Q39
/*
void fun(int *i)
{
        *i = *i >> *i - 1;
}
*/

// Q40
#define A    0
#define B    A+1
#define C    1-B
#define D    1-A+1
#define E    1-0+1

/*
 * 
 */
int main(int argc, char** argv) {
    
    // Q1: 1
    /*
    int a = 1, b = 1, c = 1, i = 1;
    i = b < a < c;
    cout << i;
    */
    
    // Q4: OneOne is wrong, One is right
    /*
    One arr[2];
    for(int i = 0; i < 1; i++)  // i < 1, not i < 2
        arr[i].out();
    */
    
    // Q6: -5
    /*
    double dbl = -5.55;
    cout << (int)dbl;
    */
    
    // Q7: 4
    /*
    int var = 2;
    foo(var);
    cout << var;
    */
    
    // Q8: 2.2
    /*
    int a = -1, *p = &a;
    cout << ((p == NULL) ? 1.1 : 2.2);
    return 0;
    */
    
    // Q9: The array may be initialized at the time of declaration. is wrong, implicitly allocated variables are not initialized
    /*
    char array[255]; // Not initialized
    int i; // Not initialized
    int* k = new int; // Not initialized due to basic type, no default constructor
    static char arrayStatic[255]; // Initialized
    static int j; // Initialized
    string* str = new string; // Initialized to ""
    cout << array[0] << endl;
    */
    
    // Q10: 0
    /*
    int *Int = new int;
    *Int = 1 / 2 * 2 / 1. * 2. / 4 * 4; // 0
    cout << *Int;     
    float Float = 1 / 2;
    cout << Float << endl; // 0
    */
    
    // Q12: virtual void foo(){ cout << 1; }
    /*
    One   o1;
    Two   o2;
    Three o3;
    One *o = &o1;
    o->foo();
    o = &o2; o->foo();
    o = &o3; o->foo();
    */
    
    // Q13: using namespace Space::a; is wrong, using Space::a; is right
    // using namespace Space::a; // error: 'a' is not a namespace-name
    /*
    using Space::a;
    cout << a << " " << b;
    */
    
    // Q14: 010
    /*
    int i = 0;
    cout << i; 
    { int i = 1; cout << i; }
    { int i = 2; }
    cout << i;
    */
    
    // Q15: Compilation fails
    /*
    bar b;
    b.assign(); // error: 'int foo::p' is private
    b.out();
    */
    
    // Q16: Hello
    /*
    char str[] = "Hello\0World\0";
    cout << str;
    */
    
    // Q18: Hello world 
    /*
    char i = '1';
    switch(i)
    {
        case '1':
            cout<<"Hello ";
        case '2':
            cout<<"world "; break;
        case '3':
            cout<<"!";
    }
    */
    
    // Q19: d
    /*
    int a = 'a', b = 3;
    char *f;
    f = inc(a,b);
    cout << *f;
    */
    
    // Q20: mine
    /*
    a b;
    try  { throw b; }
    catch (a& e)  { cout << e.whose() << endl; }
    */
    
    // Q21: cout << char('a' + r) << s;
    /*
    Beta b;
    b.assign();
    b.out();
    */
    
    //  Q22: -1-2
    /*
    int a = 0, b = 1, c, d;
    c = sub(a,b);
    d = sub(c,b);
    cout << c << d;
    */
    
    // Q24: barfoo
    /*
    string s1 = "foo";
    string s2;
    getline(cin,s2);
    cout << s2.append(s1);
    */
    
    // Q25: c
    /*
    char array[3]={'a', 'b', 'c'};
    fun(array + 1);
    cout << fun(array + 1);
    */
    
    // Q26: abcdabcd is wrong, abcd is right
    /*
    string s;
    s = "abcd";
    s.append(s);
    s.resize(s.size() / 2); // Resizes the string to a length of n characters.
                            // If n is smaller than the current string length, 
                            // the current value is shortened to its first n character, 
                            // removing the characters beyond the nth.
    // Messed with string::reserve()
    s.reserve(s.size() / 2); // Not alter the string content
    cout << s;
    */
    
    // Q27: 221111
    /*
    C2 c;
    c.foo();
    */
    
    // Q28: 6
    /*
    int i = 0;
    for(int a = 0; a < 2; a++)
        i = f(i + 1);
    cout << i;
    */
    
    // Q29: 00
    /*
    Zero *obj;
    One obj1;
    obj = &obj1;
    obj->out();
    Two obj2;
    obj = &obj2;
    obj->out();
    */
    
    // Q31: cout << fun("ab"); cout << fun("abba"); cout << fun(*s);
    /*
    string *s = new string("ab");
    //insert code here
    cout << fun("ab") << endl;
    cout << fun("abba") << endl;
    cout << fun(*s) << endl;
    */
    
    // Q32: A__Z is wrong, A_A__Z is right
    /*
    string s1[]= {"A","Z"};
    string s="";
    for (int i=0; i<2; i++) 
        cout << s.append(s1[i]).insert(1,"_"); // 1st loop prints "A_", 2nd loop prints "A__Z"
    */
    
    // Q33: 1
    /*
    float x = 0.9, y=-0.5;
    int i,j = 1;
    i = x + j + y;
    cout << i;
    */
    
    // Q34: -1
    /*
    int i = 1;
    if (--i == 1) {
        cout << i;
    } else {
        cout << --i;
    }
    */
    
    // Q35: 13
    /*
    var++;
    Static(var++);
    cout << var << Static(var);
    */
    
    // Q36: 102 is wrong, 120 is right
    /*
    enum answer { yes, no, whoknows };
    enum answer a[3];
    a[0] = no;
    a[2] = yes;
    a[1] = whoknows;
    for(int i = 0; i < 3; i++)
      cout << a[i];
    */
    
    // Q38: void set(char c = 'd') { value = c; }
    /*
    Class a,*b;
    b = new Class();
    b->set('a');
    b->print();
    delete b;
    a.print();
    a.set('c');
    a.print();
    a.set();
    a.print();
    */
    
    // Q39: 1
    /*
    int i = 2;
    fun(&i);
    cout << i;
    */
    
    // Q40: 0 is wrong, 2 is right
    cout << C << endl; // 1-B == 1-A+1 == 1-0+1 == 2
    cout << B << endl;
    cout << D << endl;
    cout << E << endl;
    
    return 0;
}

