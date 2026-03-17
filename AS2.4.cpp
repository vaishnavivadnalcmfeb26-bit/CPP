Q4.1 Write a program that: 
 Uses new to allocate an array of 5 integers 
 Takes user input 
 Prints the values 
 Deallocates memory using delete[]
Answer :

#include <iostream>
using namespace std;

int main() {
    // 1. Allocate memory for 5 integers using 'new'
    int* arr = new int[5];

    // 2. Take user input
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // 3. Print the values
    cout << "The values are: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    // 4. Deallocate memory using 'delete[]'
    delete[] arr;
    cout << "\nMemory successfully freed using delete[]." << endl;

    return 0;
}

//
4.2 Repeat Q4.1 using malloc and free. 
Answer : 
//

#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
    // 1. Allocate memory for 5 integers using 'malloc'
    // (int*) is casting, sizeof(int)*5 calculates the total bytes needed
    int* arr = (int*)malloc(5 * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        cout << "Memory allocation failed!";
        return 1;
    }

    // 2. Take user input
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // 3. Print the values
    cout << "The values are: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    // 4. Deallocate memory using 'free'
    free(arr);
    cout << "\nMemory successfully freed using free()." << endl;

    return 0;
}

//

Q4.3 — Explain: 
 Why constructors are not called when using malloc 
Answer :
malloc is a function from the C language that only allocates raw bytes of memory. It doesn't understand C++ objects or classes, so it simply provides space without "setting up" the object. new, on the other hand, is a C++ operator specifically built to allocate memory and immediately run the constructor.

 Why new is preferred in C++ 
Answer : 
In C++, new is preferred because it automatically calls constructors to initialize objects, whereas malloc leaves memory uninitialized. It is type-safe, returning the correct pointer type without needing manual casting. Additionally, new calculates memory size automatically without using sizeof() and handles errors by throwing exceptions instead of just returning NULL.

 Difference in return types and initialization  
Answer :
1. Return Type
new: Returns the correct data type (e.g., int*). You don't have to do anything extra.
malloc: Returns a void* (a generic pointer). You must manually "cast" (convert) it to the type you need.
2. Initialization
new: It builds and sets up the object by calling the constructor. The data is ready to use.
malloc: It only gives you empty space. It doesn't set anything up, so the memory contains "garbage values" (old random data).

 Why malloc cannot initialize complex types 
Answer : 
malloc cannot initialize complex types because it is a memory-only function. It only knows how to reserve a block of raw bytes; it does not know about C++ classes or objects.
Complex types (like classes) require a constructor to be called to set up their internal data and logic. Since malloc cannot call constructors, the object is never "built" properly and remains unusable.

//