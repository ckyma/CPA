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

/*
 * 
 */
int main(int argc, char** argv) {
    
    // 7.4 Catching exceptions
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
    
    
    
    return 0;
}

