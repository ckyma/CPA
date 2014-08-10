/* 
 * File:   main.cpp
 * Author: phinary0
 *
 * Created on August 9, 2014, 1:51 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

void PlayWithNumber(int x) { }
void PlayWithNumber(float x) { }

int main(int argc, char** argv) {
    
    // error: call of overloaded ‘PlayWithNumber(double)’ is ambiguous
    // literal 1.0 is type double not float, and can NOT be promoted to either float nor int 
    /*
    PlayWithNumber(1.0); // error
    */
    PlayWithNumber(1.0f); // succeed
    
    
    
    return 0;
}

