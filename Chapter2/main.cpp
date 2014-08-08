/* 
 * File:   main.cpp
 * Author: phinary0
 *
 * Created on August 8, 2014, 8:54 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // Q1: 0 is right
    /*
    int i = 0, j = i++, k = --i;
    // Now, i == 0 after i++ and --i (made a mistake here), j == 0, k == 0
    if(i > 0)
        j++;
    else
        k++;
    if(k == 0)
        i++;
    else if(k > 0)
        k--;
    else
        k++;
    cout << i * j * k;
    */
    
    // Q2: 0 is wrong, 4 is right
    /*
    int i = 1, j = i++, k = --i;
    if(i > 0) {
        j++;
        k++;
    }
    else {
        k++;
        i++;
    }
    if(k == 0) {
        i++;
        j++;
    }
    else {
        if(k > 0)
            k--;
        else
            k++;
        i++;
    }
    cout << i * j * k;
    */
    
    // Q3: 1000000000000000.0000000000000001 is wrong, 1000000000000000.000000 is right
    double big = 1e15;
    double small = 1e-15;
    
    // Caution: 'fixed' is set with default 'precision' of 6 digits
    cout << fixed << big + small;
    
    return 0;
}

