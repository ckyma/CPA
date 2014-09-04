/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on September 3, 2014, 7:49 PM
 */

#include <iostream>
#include "mystack.h"

using namespace std;

// 8.3
bool f1(){
    cout << "f1" << endl;
    return false;
}
bool f2(){
    cout << "f2" << endl;
    return true;
}
class V {
public:
    int vec[2];
    V(int a0, int a1) { vec[0]=a0; vec[1]=a1; }
    bool operator&&(V &arg) {
        return abs(vec[0]) + abs(vec[1]) > 0 && 
               abs(arg.vec[0]) + abs(arg.vec[1]) > 0;
    }
};
bool operator!(V &v) {
    return v.vec[0] * v.vec[1] != 0;
}

// 8.4
class Fun {
public:
    int operator() (int a1, int a2) {
        return a1 > a2 ? a1 : a2;
    }
    int operator() (int a1, int a2, int a3) {
        return a1 > a2 ? (a1 > a3 ? a1 : a3) : (a2 > a3 ? a2 : a3);
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    // 8.1
    /*
    int i = 2, j;
    Stack stk;
    stk << 1 << 2 * i;
    cout << stk[0] << endl << stk[-1] << endl;
    stk[0] = stk[-1] = 0;
    stk >> i >> j;
    cout << i << endl << j << endl;
    */
    
    // 8.2
    /*
    enum weekday {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
    int day = SUNDAY;
    // weekday day1 = 0; // error: invalid conversion from ‘int’ to ‘main(int, char**)::weekday’ [-fpermissive]
    cout << day << endl;
    enum Symbols {ALPHA = -1, BETA = -2, GEMMA};
    */
    
    // 8.3
    if(f1() && f2()){ // f1 only
    }
    V v1(4, 8), v2(3, 7), v3(0, 0), v4(0, 0);
    cout << (v1 && v2 ? "true" : "false") << endl;
    // cout << (v3 && v4 && v1 ? "true" : "false") << endl; // error: no match for ‘operator&&’ in ‘v3.V::operator&&((* & v4)) && v1’
    cout << (!v1 ? "true" : "false") << endl;
    
    // 8.4
    Fun f; // Functor
    cout << f(1,2) << endl;
    cout << f(1,2,3) << endl;
    
    return 0;
}

