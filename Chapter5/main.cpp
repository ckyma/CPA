/* 
 * File:   main.cpp
 * Author: phinary0
 *
 * Created on August 12, 2014, 7:27 PM
 */

#include <iostream>

/*
 * 
 */

class Stack {
    private:
        int stackstore[100];
        int SP;
    public:
        // Error: definition of implicitly-declared ‘Stack::Stack()’
        // Constructor needs to be declared in class definition first   
        Stack(void);
        void push(int);
        int pop(void){
            return stackstore[--SP];
        }
};

// Error: definition of implicitly-declared ‘Stack::Stack()’
// Constructor needs to be declared in class definition first
Stack::Stack() : SP(0) {}

void Stack::push(int val){
    stackstore[SP++] = val;
}

class AddingStack : Stack {
    private:
	int sum;
    public:
	AddingStack(void);
	void push(int value);
	int pop(void);	
	int getSum(void);
};
// No need to re-define, can call superclass constructor after ':'
AddingStack::AddingStack(void) : sum(0), Stack() {
    //sum = 0;
}
void AddingStack::push(int value) {
    sum += value;
    // No need to re-define, can call superclass method
    Stack::push(value);
}
int AddingStack::pop(void) {
    // No need to re-define, can call superclass method
    int val = Stack::pop();
    sum -= val;
    return val;
}
int AddingStack::getSum(void) {
    return sum;
}

using namespace std;

int main(int argc, char** argv) {
    
    AddingStack super_stack;
	
    for(int i = 1; i < 10; i++)
            super_stack.push(i);
    cout << super_stack.getSum() << endl;
    for(int i = 1; i < 10; i++)
            super_stack.pop();
    cout << super_stack.getSum() << endl;
    
    return 0;
}

