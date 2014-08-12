/* 
 * File:   main.cpp
 * Author: phinary0
 *
 * Created on August 11, 2014, 3:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void printInfo(const string &s) { 
    cout << "length = " << s.length() << endl; 
    cout << "capacity = " << s.capacity() << endl; 
    cout << "max size = " << s.max_size() << endl; 
    cout << "---------" << endl; 
} 

/*
 * 
 */
int main(int argc, char** argv) {
    
    // 4.1.9
    // Use pointer to pointer and array of pointers to define multiple dimension array, 
    // even with different second dimensions.
    // For example, a Triangular matrix:
    /*
    int rows = 5, cols = 5;
    int **arr;
    // allocate and initialize the array
    arr = new int * [rows];
    for (int r = 0; r < rows; r++) {
        arr[r] = new int[r + 1];
        for(int c = 0; c <= r; c++)
            arr[r][c] = (r + 1) * 10 + c + 1;
    }
    // print the array reversed to the order of allocations
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c <= r; c++)
            cout << arr[r][c] << " ";
        cout << endl;
    }
    // free the array
    for(int r = 0; r < rows; r++)
        delete [] arr[r];
    delete [] arr;
    */
    
    // 4.2.4 
    // Equal after Conversion if promoted, i.e. larger memory
    /*
    short s = 32767; 
    int i = s; 
    if(i == s) 
        cout << s << " equal " << i << endl; 
    else 
        cout << "not equal" << endl;
    // Not equal after Conversion if downgraded, even value may not seem lost
    double d = 123456.789012; 
    float f = d; // f lose precision == 123456.789062
    if(d == f) 
        cout << "equal" << endl; 
    else 
        cout << fixed << d << " not equal " << f << endl; // 123456.789012 not equal 123456.789062
    // Extreme large or small values out of target range
    float x = 1e100;
    int m = x;
    cout << m << endl; // -2147483648, out of int range
    */
    
    // 4.3: String
    // Uniform or extended initializer {} Need support of C++11
    // Using Netbeans needs Projects -> Right Click -> Properties -> Build -> C++ Compiler -> add Additional Options "--std=c++0x"
    /*
    string Greet = "Hello";
    string Greet1("Hellox2");
    char Greet2[] {"Hellox3"};
    string Greet3 {"Hellox4"};
    cout << Greet << Greet1 << Greet2 << Greet3 << endl;
    // + operator can NOT be used for two string literal
    string String;
    // String = "A" + "B"; // error: invalid operands of types ‘const char [2]’ and ‘const char [2]’ to binary ‘operator+’
    String = String + "C";
    String = "B" + String; 		
    cout << String << endl; 
    // Use getline function instead of cin, due to white space " " is delimiter
    string LineOfTypes; 
    getline(cin,LineOfTypes); 
    cout << LineOfTypes << endl; 
    // 'a' > 'A', 'a' > '1' (number), 'a' < 'z'
    string str1, str2; 
    cout << "Enter 2 lines of text:" << endl; 
    getline(cin,str1); 
    getline(cin,str2); 
    cout << "You've entered:'" << endl; 
    if(str1 == str2) 
        cout << "\"" << str1 << "\" == \"" << str2 << "\"" << endl; 
    else if(str1 > str2) 
        cout << "\"" << str1 << "\" > \"" << str2 << "\"" << endl; 
    else 
        cout << "\"" << str1 << "\" < \"" << str2 << "\"" << endl; 
    */
    
    // 4.4
    string str = "12345"; 
    int pos = 1; 
    // int pos = 2; // terminate called after throwing an instance of 'std::out_of_range'
    cout << str.substr(pos).substr(pos).substr(pos).size() << endl; 
    // string.substr() range
    string S = "ABC"; 
    cout << (S.substr(2,1) == S.substr(2,2)) << endl; // 1, i.e. not equal
    cout << S.compare(2,1,S,2,2) << endl; // 0, i.e., equal
    string S1 = S.substr(2,1); // string.substr() only include the valid characters in range
    cout << S1 << endl; // 'C'
    cout << (S.substr(2, 100) == "C") << endl; // 1, i.e., true or equal
    cout << S.compare(2, 1, S1) << endl; // 0, i.e., equal
    cout << S.compare(1,1,"BC") + S.compare(2,1,S,2,2) << endl;  // -1
    // string.find() uses string::npos as not found
    string greeting = "My name is Bond, Jams Bond."; 
    string we_need_him = "James"; 
    if(greeting.find(we_need_him) != string::npos) 
        cout << "OMG! He's here!" << endl; 
    else 
        cout << "It's not him." << endl; 
    int comma = greeting.find(','); 
    if(comma != string::npos) 
        cout << "Curious. He used a comma at " << comma << "." << endl;
    // string.capacity() and string.max_size()
    string TheString = "content"; 
    printInfo(TheString); 
    for(int i = 0; i < 10; i++) 
        TheString += TheString; 
    printInfo(TheString); 
    
    return 0;
}

