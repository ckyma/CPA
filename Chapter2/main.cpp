/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on August 8, 2014, 8:54 PM
 * 
 * Chapter 2 Assessment
 * 
 */

#include <iostream>

using namespace std;

/*
 * 
 */

// Q9
/*
struct str {
    int t[3];
    char s[3];
};
*/

// Q10
/*
struct sct {
    int t[2];
};  
struct str {
    sct t[2];
};
*/

int main(int argc, char** argv) {
    
    // switch
    int score = 120;
    switch (score){
        default:
            cout << "Default" << endl;
        case 1:
            cout << 1 << endl;
            break;
        // case 10/6:  // error: duplicate case value
        // case 2.2:   // error: case label does not reduce to an integer constant
        case 13/6:
            cout << 2 << endl;
            // continue;   // error: continue statement not within a loop
        case 'a':
            cout << 'a' << endl;
    }
    /*
    string day = "SUN";
    switch (day){           // error: switch quantity not an integer
        case "MON":
            cout << "Monday" << endl;
            break;
        default: 
            cout << "Default" << endl;
    }
    */
    
    /**
     * Assessment 1
     */
    
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
    int i = 1, j = i++, k = --i;     // k = --2 == 1, i == 2 => == 1
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
    cout << i * j * k;  // i == 2, j == 2, k == 1
    */
    
    // Q3: 1000000000000000.0000000000000001 is wrong, 1000000000000000.000000 is right
    /*
    double big = 1e15;
    double small = 1e-15;
    
    // Caution: 'fixed' is set with default 'precision' of 6 digits
    cout << fixed << big + small;
    */
    
    // Q4: 5 right
    /*
    int i = 5, j = 0;
    while(i > 0) {
        i--;
        j++;
    }
    cout << j;
    */
    
    // Q5: 4 right
    /*
    int i = 3, j = 0;
    do {
        i--;
        j++;
    } while(i >= 0);
    cout << j;
    */
    
    // Q6: *** right
    /*
    float val = 100.0;
    do {
        val = val / 5;
        cout << "*";
    } while(val > 1.0);
    */
    
    // Q7: 5 is wrong, 4 is right
    /*
    int a = 2;
    // '<<' is binary operator returning rvalue, (2 << 2) == 2 * 2^2 == 8
    switch(a << a) {
        case 8 : a++;
        // No break here, so continue, a == 3
        case 4 : a++;
        // No break here, so continue, a == 4
        case 2 : break;
        case 1 : a--;
    }
    cout << a;
    */
    
    // Q8: 2 right
    /*
    int t[] = { 8, 4, 3, 2, 1 }, i;
    for(i = t[4]; i < t[0]; i++)
        t[i - 1] = -t[3];
    cout << i;
    */
    
    // Q9: y21 right
    /*
    str a = { 1, 2, 3, 'a', 'b', 'c' };
    str b = { 5, 6, 7, 'x', 'y', 'z' };
    cout << char(b.s[0] + a.t[0]) << int(a.s[2] - a.s[0]) << int(b.s[2] - b.s[1]);
    */
    
    // Q10: 34 right
    /*
    str t[2] = { {0, 2, 4, 6}, {1, 3, 5, 7} };
    cout << t[1].t[0].t[1] << t[0].t[1].t[0];
    */
    
    /**
     * Assessment 2
     */
    
    // Q1 is A1.Q3
    
    // Q2: true right
    /*
    bool yes = !false;
    bool no = !yes;
    if(!no)
        cout << "true";
    else
        cout << "false" ;
    */
    
    // Q3 is A1.Q4
    
    // Q4 is A1.Q5
    
    // Q5: **** is wrong, ***** is right
    // last one is val == -160 < 100.0, not 80
    /*
    for(float val = -10.0; val < 100.0; val = -val * 2)
        cout << "*";
    */
    
    // Q6: **
    /*
    for(float val = -10.0; val < 100.0; val = -val * 2) {
        if(val < 0 && -val >= 40)
            break;
        cout << "*";
    }
    */
    
    // Q7: 113
    /*
    int a = 1, b = 2;
    int c = a | b;
    int d = c & a;
    int e = d ^ 0;
    cout << e << d << c;
    */
    
    // Q8 is A1.Q7
    
    // Q9: true is wrong, 1 is right
    // cout << true output is number 1
    /*
    bool t[5];
    for(int i = 0; i < 5; i++)
        t[4 - i] = !(i % 2);
    cout << t[0] && t[2];
    */
    
    // Q10: ****
    char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
    for(int i = 1; i < 5; i++) {
        cout << "*";
        if((arr[i] - arr[i - 1]) % 2)
            continue;
        cout << "*";
    }
    
    return 0;
}

