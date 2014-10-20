/* 
 * File:   main.cpp
 * Author: CY
 *
 * Created on August 9, 2014, 1:51 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

// 3.8.5
void PlayWithNumber(int x) { }
void PlayWithNumber(float x) { }

// Q3
/*
int fun(float a, float b) {
    return a / b;
}
*/

// Q4
/*
int f1(int a) {
    return ++a;
}
int f2(int &a) {
    return ++a;
}
int f3(int *a) {
    return *a + 1;
}
*/

// Q5
/*
int f1(int *a) {
    return *a + 1;
}
int *f2(int *a) {
    return a + 1;
}
int *f3(int &a) {
    return &a + 1;
}
*/

// Q6
/*
int fun(int p1 = 1, int p2 = 1) {
    return p2 << p1;
}
*/

// Q7
/*
string fun(string t, string s = "x", int r = 1) {
    while(--r)
        s += s;
    t = t + s;
    return s;
}
*/

// Q8
/*
int fun(int a, int b) {
    return a + b;
}
int fun(int a, char b) {
    return b - a;
}
int fun(float a, float b) {
    return a * b;
}
*/

// Q9
/*
int fun(long a, long b = 1) {
    return a << b;
}
int fun(int a, char b = 'z') {
    return b - a;
}
int fun(float a, float b = 0) {
    return a * b;
}
*/

// Q10
int fun(long a) {
    return a / a;
}

int fun(int a) {
    return 2 * a;
}

int fun(double a = 3.0) {
    return a;
}


int main(int argc, char** argv) {
    
    // 3.1.22: how this computer and compiler use the memory
    /*
    cout << "This computing enviroments uses:" << endl;
    cout << sizeof(char) << " byte for chars" << endl;
    cout << sizeof(short int) << " bytes for shorts" << endl;
    cout << sizeof(int) << " bytes for ints" << endl;
    cout << sizeof(long int) << " bytes for longs" << endl;
    cout << sizeof(float) << " bytes for floats"  << endl;
    cout << sizeof(double) << " bytes for doubles"  << endl;
    cout << sizeof(bool) << " byte for bools" << endl;
    cout << sizeof(int *) << " bytes for pointers" << endl;
    */
    
    // 3.8.5: The C++ language compiler tries to promote the types,
    // if there is no exact fit (as in our example: obviously a float is not a double).
    // error: call of overloaded ‘PlayWithNumber(double)’ is ambiguous
    // literal 1.0 is type double not float, and can NOT be promoted to either float nor int 
    int score1 = 1.2;   // implicit type-casting from double to int, downgraded
    float score2 = 1.1; // implicit type-casting from double to float, downgraded
    score2 = 1.2;
    cout << score1 << endl;     // 1
    cout << score2 << endl;     // 1.2
    cout << 1/1.2 << endl;     // 0.833333, promoted to the larger type
    // PlayWithNumber(1.0); // error
    PlayWithNumber(1.0f); // succeed
    
    
    // 3.10.2: error for void *ptr; *ptr = 1 or *ptr;
    /*
    void *ptr;
    // *ptr = 1; // error: ‘void*’ is not a pointer-to-object type
    int a = 1, *ptr_int;
    ptr_int = &a;
    ptr = ptr_int;
    // cout << *ptr; // error: ‘void*’ is not a pointer-to-object type
    cout << *((int*)ptr) << endl; // force conversion to int*, succeed
    */
    
    // 3.10.8: Bubble sort improved
    /*
    int *numbers, how_many_numbers;
    int  aux;
    bool swapped;
    
    cout << "How many numbers are you going to sort? ";
    cin >> how_many_numbers;
    if( how_many_numbers <= 0 || how_many_numbers > 1000000) {
        cout << "Are you kidding?" << endl;
        return 1;
    }
    numbers = new int[how_many_numbers];
    for(int i = 0; i < how_many_numbers; i++) {
        cout << "\nEnter the number #" << i + 1 << ": ";
        cin >> numbers[i];
    }
    do {
        swapped = false;
        for(int i = 0; i < how_many_numbers - 1; i++)
            if(numbers[i] > numbers[i + 1]) {
                swapped = true;
                aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
    } while(swapped);
    cout << endl << "The sorted array:" << endl;
    for(int i = 0; i < how_many_numbers; i++)
        cout << numbers[i] << " ";
    cout << endl;
    delete [] numbers;
    */
    
    /**
     * Assessment
     */
    // Q1: 32 is wrong, 22 is right.
    // ++ has a high priority than *, so *ptr++ == *(ptr++)
    /*
    int t[3] = { 3, 2, 1 }, *ptr = t + 1;
    (*(ptr + 1))++;
    *ptr++;
    cout << t[1] << t[2];
    */
    
    // Q2: 1 is wrong, 0 is right.
    // p2 - p1 == 1 == (p2 - p1) already /sizeof(float), sizeof(float) == 4 here, both are int
    // (p2 - p1)/sizeof(float) == 0, i.e. int value
    // (float) (p2 - p1)/sizeof(float) == 0.25
    /*
    float f[2];
    float *p1 = f, *p2 = p1 + 1;
    cout << (p2 - p1) / sizeof(float); // 1/4 == 0
    // cout << 1/4; // 0
    // cout << (float) (p2 - p1) / sizeof(float); // (float) 1/4 == 0.25
    */
    
    // Q3: 0
    /*
    cout << fun(fun(1.0,2.0),fun(2.0,1.0));
    */
    
    // Q4: 334
    /*
    int value = 2;
    cout << f1(value);
    cout << f2(value);
    cout << f3(&value);
    */
    
    // Q5: 3
    /*
    int t[] = {0, 1, 2, 3};
    cout << f1(f3(*f2(t)));
    */
    
    // Q6: 16
    /*
    cout << fun(fun(),fun(2));
    */
    
    // Q7: xa
    /*
    string name = "a";
    cout << fun(name);
    cout << name;
    */
    
    // Q8: 124
    /*
    cout << fun(1,0) << fun('a','c') << fun(2.f,2.f);
    */
    
    // Q9: 220
    /*
    cout << fun(1L) << fun('x') << fun(2e0f);
    */
    
    // Q10: 111
    cout << fun(1000000000L) << fun (1L) << fun(1.f);
    
    return 0;
}

