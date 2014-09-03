/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on September 3, 2014, 7:49 PM
 */

#include <iostream>
#include "mystack.h"

using namespace std;

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
    enum weekday {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
    int day = SUNDAY;
    // weekday day1 = 0; // error: invalid conversion from ‘int’ to ‘main(int, char**)::weekday’ [-fpermissive]
    cout << day << endl;
    
    enum Symbols {ALPHA = -1, BETA = -2, GEMMA};
    
    
    return 0;
}

