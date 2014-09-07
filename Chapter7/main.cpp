/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on September 1, 2014, 8:31 PM
 */

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

// 7.4
/*
void function(int i) {
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        // case 3: throw exception("3"); // error: no matching function for call to ‘std::exception::exception(const char [2])’
        case 3: throw range_error("2");
        case 4: throw exception();
        case 5: throw "so bad";
    }
}
void broker(int i) {
    try {
        function(i);
    }
    catch(...) {
        cout << "Broker swept problems under the carpet " << endl;
        throw;
    }
}
*/

// Assessment
// Q4
/*
class X {
public:
    X(void) { cout << 1; }
    ~X(void) { cout << 2; }
};        
X *exec() {
    X *x = new X();
    throw string("0");
    return x;
}
*/

// Q5
/*
class X {
public:
    X(void) { cout << 0; }
    ~X(void) { cout << 2; }
};
*/

// Q6
/*
class X : public logic_error {
public:
    X() : logic_error("0") {};
};
void z() throw(X) {
    throw new logic_error("0"); // Throw a pointer to logic_error object. terminate called after throwing an instance of 'std::logic_error*'
    // throw logic_error("0"); // runtime error: what(): 0
    // throw X(); // 0 without error
}
*/

// Q7
class E {};
class X {
    static int c;
public:
    X() { if(c++ > 2) throw new E; } // Throw pointer to a E object only when c > 2,
    ~X() { if(c++ > 2) throw new E; } // i.e. after cout << i before exit of f to destruct
};
int X::c = 0;
void f(int i) {
    X a,b;
    cout << i;
}


/*
 * 
 */
int main(int argc, char** argv) {
    
    // 7.4 Catching exceptions
    /*
    for(int i = 0; i < 4; i++) {
        try {
            function(i);
        }
        // In NetBeans, the exception class doesn't have a string to define what()
        // So all 4 exceptions print the same "Exception caught: std::exception"
        catch(exception ex) {
            cout << "Exception caught: " << ex.what() << endl;
        }
    }
    for(int i = 0; i < 6; i++) {
        try {
            function(i);
        }
        catch(out_of_range ofr) {
            cout << "Out of range: " << ofr.what() << endl;
        }
        catch(overflow_error ovf) {
            cout << "Overflow: " << ovf.what() << endl;
        }
        catch(domain_error dmn) {
            cout << "Domain: " << dmn.what() << endl;
        }
        catch(runtime_error re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) { // runtime error without this case due to the last unhandled string type "so bad"
            cout << "Something bad happened" << endl;
        }
    }
    for(int i = 0; i < 5; i++) {
        try {
            broker(i);
        }
        catch(logic_error le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }
    */
    
    // Assessment: 90%
    // Q4: 10
    /*
    X *x;
    try {
        delete exec(); // Destructor is never called due to exception before that
    } catch(string &s) {
        cout << s;
    }
    */
    
    // Q5: 01
    /*
    try {
        X *x = new X();
    throw true;
        delete x;
    } catch(bool s) {
        cout << s;
    }
    */
    
    // Q6: Execution fails
    /*
    X x;
    try {
        z();
    }
    catch(X &i) { // terminate called after throwing an instance of 'std::logic_error*'
        cout << i.what();
    }
//    catch(logic_error *i) { // terminate called after throwing an instance of 'std::logic_error*'
//        cout << i->what();
//    }
    */
    
    // Q7: Execution fails is wrong, 01 is right
    try {
        f(0);
        f(1);
    } catch(...) {
        cout << 1;
    }
    
    cout << endl << "Execution continues if the exception could be caught." << endl;
    
    return 0;
}

