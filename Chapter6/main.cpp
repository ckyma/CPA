/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on August 14, 2014, 2:32 PM
 */

#include <iostream>

using namespace std;

// 6.1
/*
class Super {
// private:
protected:
    int storage;
public:
    void put(int val) { storage = val; }
    int get(void) { return storage; }
};
// Without specifier 'public' before Super, member functions are not callable
// class Sub : Super { }; // error
class Sub : public Super { 
public:
    // storage is not accessible by declare 'private', should be 'protected'
    void print(void) { cout << "storage = " << storage << endl; }
};
*/

// 6.2
/*
class Pet {
protected:
    string Name;
public:
    Pet(string n) { Name = n; }
    void Run(void) { cout << Name << ": I'm running" << endl; }
};
class Dog : public Pet {
public:
    Dog(string n) : DogName(n), Pet(n) {};
    string DogName;
    void MakeSound(void) { cout << Name << ": Woof! Woof!" << endl; }
};
class Cat : public Pet {
public:
    Cat(string n) : CatName(n), Pet(n) {};
    string CatName;
    void MakeSound(void) { cout << Name << ": Meow! Meow!" << endl; }
};
class Bird : public Pet {
public:
    Bird(string n) : Age(100.0), Pet(n) {};
    float Age;
    void Laugh(int n) { cout << Name << ": Hah! Hah!" << endl; }
};
*/

// 6.3
/*
class Pet {
protected:
    string Name;
public:
    Pet(string n) { Name = n; }
    void MakeSound(void) { cout << Name << " the Pet says: Shh! Shh!" << endl; }
};
class Cat : public Pet {
public:
    Cat(string n) : Pet(n) { }
    void MakeSound(void) { cout << Name << " the Cat says: Meow! Meow!" << endl; }
};
class Dog : public Pet {
public:
    Dog(string n) : Pet(n) { }
    void MakeSound(void) { cout << Name << " the Dog says: Woof! Woof!" << endl; }
};
*/

// Assessment
// Q1
/*
class X {
private: 
    int v;
};
class Y : public X {
    Y() : v(0) {}
};
*/

// Q2
/*
class X {
protected: 
    int v;
};
class Y : protected X {
    Y() : v(0) {}
};
*/

// Q3
/*
class X { };
class Y : public X { };
class Z : public X { };
*/

// Q4
/*
class X { 
public:
    void shout() { cout << "X"; } 
};
class Y : public X { 
public:
    void shout() { cout << "Y"; }
};
*/

// Q5
/*
class X { 
public:
    virtual void shout() { cout << "X"; } // if base is virtual, all subclasses members are virtual
    //void shout() { cout << "X"; } // if not virtual
};
class Y : public X { 
public:
    void shout() { cout << "Y"; } // if base is virtual, all subclasses members are virtual
};
class Z : public Y { 
public:
    void shout() { cout << "Z"; } // if base is virtual, all subclasses members are virtual
};
*/

// Q6
/*
class A { 
public:
    A() : val(0) {}
    int val;
    void inc() { ++val; } 
};
void Do(A a) {
    a.inc();
}
*/

// Q7
/*
class A { 
public:
    A() : val(0) {}
    int val;
    int inc() { ++val; return val--; } 
};
void Do(A *a) {
    a-> val = a->inc();
}
*/

// Q8
/*
class A { 
    int *val;
public:
    A() { val = new int; *val = 0; }
    A(A &a) { val = new int; *val = a.get(); }
    int get() { return ++(*val); } 
};
*/

// Q9
/*
class A { 
public:
    int v;
    A(int x) : v(x + 1) {}
    int get() const { return v; }
};
*/

// Q10
class A { 
friend class B;
private:
    int field;
public:
    int set(int x) { return field = ++x; }
    int get() { return ++field; }
};
class B {
public:
    void kill(A &a) { a.field = 0; }
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    // 6.1
    /*
    // Private member can NOT be called by subclass
    Sub object;
    object.put(100); // error: ‘void Super::put(int)’ is inaccessible within this context
    object.put(object.get() + 1);
    cout << object.get() << endl;
    // 'storage' is not accessible by declare 'private', should be 'protected'
    object.print();
    // error: ‘int Super::storage’ is protected within this context
    // 'storage' is still not accessible even as 'protected', should be public
    // cout << object.storage << endl;
    */
    
    // 6.2
    /*
    // subclass pointer CAN be converted to superclass pointer implicitly.
    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");
    Pet *a_pet3 = new Bird("Poly");
    a_pet1 -> Run(); 
    a_pet2 -> Run();
    a_pet3 -> Run();
     // is not allowed here! since a_pet1 is superclass pointer
    // a_pet1 -> MakeSound(); // error: ‘class Pet’ has no member named ‘MakeSound’
    // a_pet2 -> MakeSound(); // error: ‘class Pet’ has no member named ‘MakeSound’
    // Use static_cast to explicitly convert superclass pointer to subclass pointer
    static_cast<Cat *>(a_pet1) -> MakeSound();
    static_cast<Dog *>(a_pet2) -> MakeSound();
    static_cast<Bird *>(a_pet3) -> Laugh(1);
    cout << static_cast<Cat *>(a_pet1) -> CatName << endl;
    cout << static_cast<Dog *>(a_pet2) -> DogName << endl;
    // static_cast does NOT do any type check. which may cause unintended error
    // Interesting result: the common base class member is saved and right, the extra target subclass members are just concatenated
    static_cast<Cat *>(a_pet2) -> MakeSound(); // dog meow
    static_cast<Dog *>(a_pet1) -> MakeSound();	// cat bark
    static_cast<Dog *>(a_pet3) -> MakeSound();	// bird MakeSound() NOT Laugh(int)
    cout << static_cast<Cat *>(a_pet2) -> CatName << endl;
    cout << static_cast<Dog *>(a_pet1) -> DogName << endl;
    // Caution
    cout << static_cast<Dog *>(a_pet3) -> DogName << endl; // No compile time error, debug shows out of bounds
    // Runtime error:  "Segmentation fault; core dumped;" means that you tried to access memory that you do not have access to.
    // Runtime stops here, no further execution due to out of bounds
    Dog *a_birddog = static_cast<Dog *>(a_pet3);
    a_birddog -> MakeSound();
    Bird *a_bird = static_cast<Bird *>(a_pet3);
    a_bird -> Laugh(1);
    // dynamic_cast can downcast (convert from pointer-to-base to pointer-to-derived) polymorphic classes (those with virtual members) if -and only if- the pointed object is a valid complete object of the target type.
    // dynamic_cast<Cat *>(a_pet1) -> MakeSound(); // error: cannot dynamic_cast ‘a_pet1’ (of type ‘class Pet*’) to type ‘class Cat*’ (source type is not polymorphic)
    // dynamic_cast<Dog *>(a_pet2) -> MakeSound(); // error: cannot dynamic_cast ‘a_pet2’ (of type ‘class Pet*’) to type ‘class Dog*’ (source type is not polymorphic)
    */
    
    // 6.3
    /*
    Cat *a_cat;
    Dog *a_dog;
    a_cat = new Cat("Kitty");
    a_dog = new Dog("Doggie");
    a_cat -> MakeSound();
    static_cast<Pet *>(a_cat) -> MakeSound();
    a_dog -> MakeSound();
    static_cast<Pet *>(a_dog) -> MakeSound();
    // dynamic_cast == Implicit conversion
    dynamic_cast<Pet *>(a_dog) -> MakeSound(); // the Pet says: Shh! Shh!
    // Implicit conversion
    Pet *a_pet = a_cat;
    a_pet -> MakeSound(); // the Pet says: Shh! Shh!
    */
    
    // Assessment
    // Q1: Compilation fails
    /*
    Y y;
    cout << y.v; // error: 'int X::v' is private
    */
    
    // Q2: 0 is wrong, Compilation fails is right
    /*
    Y *y = new Y(); // error: 'Y::Y()' is private
    // Explicit Constructors have to be public
    // Y *y = new Y; // error: 'Y::Y()' is private
    cout << y->v; // error: 'int X::v' is protected
    delete y;
    */
    
    // Q3: Compilation fails
    /*
    Z *z = new Z();
    Y *y = new Y();
    z = y; // error: cannot convert 'Y*' to 'Z*' in assignment
    cout << (z == y); // error: comparison between distinct pointer types 'Z*' and 'Y*' lacks a cast
    */
    
    // Q4: Y
    /*
    X *x = new Y();
    static_cast<Y *>(x) -> shout();
    */
    
    // Q5: X is wrong, Z is right
    // If base is virtual, all subclasses are virtual as well, no matter how many inheritance
    /*
    Y *y = new Z();
    dynamic_cast<X *>(y) -> shout(); // Z
    y -> shout(); // Z
    */
    
    // Q6: 1
    /*
    A a;
    Do(a);
    a.inc();
    cout << a.val;
    */
    
    // Q7: 2
    /*
    A a;
    Do(&a);
    cout << a.inc();
    */
    
    // Q8: 22
    /*
    A a,b = a;
    cout << a.get() << b.get();
    */
    
    // Q9: Compilation fails is wrong, 33 is right
    /*
    A a(2);
    // There is an explicit copy constructor, no error here
    A b(a);
    cout << a.get() << b.get();
    */
    
    // Q10: 1
    A a; B b;
    a.set(1);
    b.kill(a);
    cout << a.get();
    
    return 0;
}
