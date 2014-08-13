/* 
 * File:   main.cpp
 * Author: phinary0
 *
 * Created on August 12, 2014, 7:27 PM
 */

#include <iostream>

/*
 * 
 */

using namespace std;

// 5.2 Stack
/*
class Stack {
    private:
        int stackstore[100];
        int SP;
    public:
        // Error: definition of implicitly-declared ‘Stack::Stack()’
        // Constructor needs to be declared in class definition first   
        Stack(void);
        void push(int);
        int pop(void){
            return stackstore[--SP];
        }
};

// Error: definition of implicitly-declared ‘Stack::Stack()’
// Constructor needs to be declared in class definition first
Stack::Stack() : SP(0) {}

void Stack::push(int val){
    stackstore[SP++] = val;
}

class AddingStack : Stack {
    private:
	int sum;
    public:
	AddingStack(void);
	void push(int value);
	int pop(void);	
	int getSum(void);
};
// No need to re-define, can call superclass constructor after ':'
AddingStack::AddingStack(void) : sum(0), Stack() {
    //sum = 0;
}
void AddingStack::push(int value) {
    sum += value;
    // No need to re-define, can call superclass method
    Stack::push(value);
}
int AddingStack::pop(void) {
    // No need to re-define, can call superclass method
    int val = Stack::pop();
    sum -= val;
    return val;
}
int AddingStack::getSum(void) {
    return sum;
}
*/

// 5.3: 
// Copy constructor
/*
class Class1 {
    public:
	Class1(int val) { this -> value = val; }
	Class1(Class1 const &source) { value = source.value + 100; }
	int value;
};
class Class2 {
    public:
	Class2(int val) { this -> value = val; }
	int value;
};
// Destructor
class Class {
    public:
	Class(int val) { 
		value = new int[val]; 
		cout << "Allocation (" << val << ") done." << endl; 
	}
	~Class(void) {
		delete [] value;
		cout << "Deletion done." << endl;
	}
	int *value;
};
void MakeALeak(void) {
    Class object(1000);
}
*/

// 5,4: Static components
/*
class Class {
    private:
	static int Counter;
    public:
	Class(void) { 
            ++Counter; 
	};
	~Class(void) { 
            --Counter; 
            if(Counter == 0) 
                cout << "Bye, bye!" << endl; 
	};
	void HowMany(void) { cout << Counter << " instances" << endl; }
        static void HowManyStatic(void) { cout << Counter << " instances" << endl; }
};
int Class::Counter = 0;
*/

// 5.5
// Pointer of object array
/*
class Array {
    private:
	int *values;
	int  size;
    public:
	Array(int siz) { 
            size = siz; values = new int[size];
            cout << "Array of " << size << " ints constructed." << endl; 
	}
	~Array(void) { 
            delete [] values; 
            cout << "Array of " << size << " ints destructed." << endl; 
	
	}
    int Get(int ix) { return values[ix]; }
    void Put(int ix, int val) { values[ix] = val; }
};	

class Element {
	int value;
    public:
	Element(void) { cout << "Element constructed!" << endl; }
        ~Element(void) { cout << "Element Destructed!" << endl; }
	int Get(void) { return value; }
	void Put(int val) { value = val; }
};
class Collection {
	Element el1, el2;
    public:	
	Collection(void) { cout << "Collection constructed!" << endl; }
        ~Collection(void) { cout << "Collection destructed!" << endl; }
	int Get(int elno) { return elno == 1 ? el1.Get() : el2.Get(); }
	int Put(int elno, int val) { if(elno == 1) el1.Put(val); else el2.Put(val); }
};
class Subelement : Element {
    public:
	Subelement(void) { cout << "Subelement constructed!" << endl; }
        ~Subelement(void) { cout << "Subelement Destructed!" << endl; }
};
class Subcollection : Collection {
    Subelement subel;
    public:	
	Subcollection(void) { cout << "Subcollection constructed!" << endl; }
        ~Subcollection(void) { cout << "Subcollection destructed!" << endl; }
};
*/

// Assessment
// Q1
/*
class A {
public: string a(string b) {
    return b.substr(0,2);
}};
class B {
public: string a(string b) {
    return b.substr(2,2);
}};
*/

// Q2
/*
class A {
    int data[3];
public:
    int cnt;
    void put(int v) { data[cnt++] = v; }
};
*/

// Q3
/*
class A {
    int cnt;
    void put(int v) { cout << cnt++; }
};
*/

// Q4
/*
class A {
public:
    int cnt;
    void put(int v);
};
void A::put(int v)  { cout << ++cnt; }
*/

// Q5
/*
class A {
public:
    float v;
    float set(float v) {
        v += 1.0;
        this -> v = v;
        return v;
    }
    float get(float d) {
        v += 1.0;
        return v;
    }
};
*/

// Q6
/*
class A {
public:
    float v;
    float set(float v) {
        A::v += 1.0;
        A::v = v + 1.0;
        return v;
    }
    float get(float v) {
        v += A::v;
        return v;
    }
};
*/

// Q7
/*
class A {
public:
    A() { v = 2.5; }
    float v;
    float set(float v) {
        A::v += 1.0;
        return v;
    }
    float get(float v) {
        v += A::v;
        return v;
    }
};
*/

// Q8
/*
class A {
public:
    A(A &a) { v = a.get(0.0); }
    A(float v) { A::v = v; }
    float v;
    float set(float v) {
        A::v += v;
        return v;
    }
    float get(float v) {
        return A::v + v;
    }
};
*/

// Q9
/*
class A {
public:
    float v;
    A() { v = 1.0; }
    A(A &a) { A::v = a.v; cout << "1"; }
    ~A() { cout << "0"; }
    float set(float v) {
        A::v = v;
        return v;
    }
    float get(float v) {
        return A::v;
    }
};
*/

// Q10
class A {
public:
    float v;
    A() : v(1.0) {}
    A(A &a) : v(2.0) {}
    A(float f) : v(3.0) {}
    float get() {
        return A::v;
    }
};


int main(int argc, char** argv) {
    
    // 5.2 Stack
    /*
    AddingStack super_stack;
	
    for(int i = 1; i < 10; i++)
            super_stack.push(i);
    cout << super_stack.getSum() << endl;
    for(int i = 1; i < 10; i++)
            super_stack.pop();
    cout << super_stack.getSum() << endl;
    */
    
    // 5.3 
    /*
    // Copy constructor
    Class1 object11(100), object12(object11);
    Class2 object21(100), object22 = object21;
    cout << object12.value << endl;
    cout << object22.value << endl;
    // Destructor to avoid memory leak
    MakeALeak();
    */
    
    // 5.4 Static components
    /*
    Class::HowManyStatic();
    // Class::HowMany(); // Error: cannot call member function ‘void Class::HowMany()’ without object
    Class a;
    Class b;
    b.HowMany();
    Class c, d;
    b.HowMany();
    b.HowManyStatic();
    */
    
    // 5.5 
    // Pointer of object array
    /*
    Array *arr[2] = { new Array(2), new Array(2) };
    // Or alternatively
    // Array **arr; arr = new Array* [2]; arr[0] = new Array(2); arr[1] = new Array(2);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            arr[i]->Put(j, j + 10 + i);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            cout << "#" << i + 1 << ":" << arr[i]->Get(j) << "; ";
        cout << endl;
    }
    delete arr[0];	delete arr[1];
    
    // Sequence of constructor and destructor for nested classes and object members
    // For Constructor: base-class object member -> base class -> sub-class object member -> sub class
    // For Destructor: sub class -> sub-class object member -> base class -> base-class object member
    // Stack: LIFO, i.e., For Constructor: coll -> subcoll;, For Destructor: subcoll -> coll
    Collection coll;
    Subcollection subcoll;
    */
    
    // Assessment
    // Q1: CD
    /*
    A a;
    B b;
    cout << a.a(b.a("ABCD"));
    */
    
    // Q2 : 2
    /*
    A a;
    a.cnt = 0;
    a.put(1);
    a.put(1);
    cout << a.cnt;
    */
    
    // Q3: Compilation fails
    /*
    A a;
    a.cnt = 0;
    a.put(1);
    a.put(1);
    */
    
    // Q4: 1
    /*
    A a[2];
    a[0].cnt = 0;
    a[1].cnt = 1;
    a[a[0].cnt].put(a[1].cnt);
    */
    
    // Q5: 3.5
    /*
    A a;
    cout << a.get(a.set(a.set(0.5)));
    */
    
    // Q6: 2.0
    /*
    A a;
    cout << a.get(a.set(a.set(0.5)));
    */
    
    // Q7: Compilation fails
    /*
    A a;
    a.A(); // error: invalid use of ‘A::A’
    cout << a.get(a.set(1.5));
    */
    
    // Q8: 2
    /*
    A *a = new A(1.0), *b = new A(*a);
    cout << a->get(b->set(a->v));
    */
    
    // Q9: 100
    /*
    A a, b = a;
    */
    
    // Q10: 6
    A a, b(a.get()), c(b);
    cout << a.v + b.v + c.v;
    
    // Destructors are called implicitly
    return 0;
}

