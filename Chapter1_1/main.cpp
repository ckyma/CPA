/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on August 4, 2014, 8:10 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
//#include <math.h>

using namespace std;

/*
 * 
 */
void lazy(void){ }

int main(void) {
    
    lazy();
    
    cout << "It's me, your first program" << endl;
    
    // manipulators to set basefield property of stream object for int type
    int Byte = 255;
    
    cout << Byte << hex << " " << Byte << endl;
    cout << Byte << dec << " " << Byte << endl;
    cout << oct << Byte << endl;
    cout << setbase(16) << Byte << endl;
    cout << setbase(10) << Byte << endl;
    
    char Char = 'X';
    int Int = Char;
    cout << Char << " " << (int)Char << " " << Int << " " << (char)Int << endl;
    
    // manipulators to set stream object for float type
    float x = 2.5, y = 0.0000000025;
    cout << fixed << x << " " << y << endl;
    cout << scientific << x << " " << y << endl;
    std::cout.unsetf ( std::ios::floatfield );
    
    // int value;
    float value;
    float squareroot;
    
    cout << "Give me a number and I will find its square root:" << endl;
    cin >> value;
    if(value >= 0.0) {
        // the difference in C++ is that sqrt() accepts either a double, 
        // a float or a long double while sqrtf() accepts only a float.
        // squareroot = sqrt(value);
        squareroot = sqrtf(value);
        cout << "You have given: " << value << endl;
        cout << "The square root is: " << squareroot << endl;
    }
    
    // test ambiguity of g++ when overloading pow in <cmath>, but not <math.h>
    cout << pow(3, 2) << endl; // ok
    cout << pow(3, 2.0) << endl; // ok
    cout << pow(3.0, 2) << endl; // ok
    
    // Chapter 1 Assessment post-hoc testing
    int remainder1 = 1 % 2 + 4 % 2;
    cout << remainder1 << endl; // 1
    
    int remainder2 = 11 % 3 % 4;
    cout << remainder2 << endl; // 2
    
    int i = 8;
    cout << i << hex << i + i << oct << i << dec << endl; // 81010
    
    return 0;
    //return 1;
}
