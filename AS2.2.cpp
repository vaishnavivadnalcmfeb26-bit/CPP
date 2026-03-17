Q2.1 Write three functions: 
void swapByValue(int a, int b); 
void swapByAddress(int *a, int *b); 
void swapByReference(int &a, int &b); 
Call all three in main() and observe which one actually swaps values. 

Answer : 

#include <iostream>
using namespace std;

// 1. Swap by Value
// This creates COPIES of the numbers. Changes stay inside this function.
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Swap by Address
// This uses POINTERS (*) to go to the memory address and change the real values.
void swapByAddress(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. Swap by Reference
// This uses ALIASES (&). 'a' and 'b' become another name for the original variables.
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    // Test 1: By Value
    swapByValue(x, y);
    cout << "After Swap by Value: x=" << x << ", y=" << y << " (Did not swap)" << endl;

    // Test 2: By Address
    swapByAddress(&x, &y); // Sending addresses using '&'
    cout << "After Swap by Address: x=" << x << ", y=" << y << " (Swapped!)" << endl;

    // Resetting x and y to original values for the final test
    x = 10; y = 20;

    // Test 3: By Reference
    swapByReference(x, y);
    cout << "After Swap by Reference: x=" << x << ", y=" << y << " (Swapped!)" << endl;

    return 0;
}

//
Q2.2 — Answer this: 
Explain how reference variables act as aliases and how that affects swapByReference(). 

Answer : 
Aliases: A reference is just a secondary name for an existing variable. It shares the same memory address as the original, so no new memory or copy is created.

Effect on Swap: Because swapByReference() uses these aliases, it modifies the original variables directly. This is why the swap is permanent in main(), unlike "Swap by Value" which only changes temporary copies.

//