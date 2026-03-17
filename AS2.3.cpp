Q3.1 Write a program to store an integer value in a variable, then: 
 Create a pointer pointing to the variable 
 Create a reference to the same variable 
 Modify the value using pointer and reference 
Print the variable after each change.

Answer : 

#include <iostream>
using namespace std;

int main() {
    // 1. Store integer in a variable
    int num = 10;
    cout << "Original value: " << num << endl;

    // 2. Create a pointer pointing to the variable
    // '*' means pointer, '&num' gets the memory address
    int* ptr = &num; 

    // 3. Create a reference to the same variable
    // '&' here means reference (alias)
    int& ref = num; 

    // 4. Modify value using pointer
    // '*' is used here to 'dereference' (go to the address)
    *ptr = 20; 
    cout << "After pointer change: " << num << endl;

    // 5. Modify value using reference
    ref = 30; 
    cout << "After reference change: " << num << endl;

    return 0;
}


//
Q3.2 — Explain: 
 Two differences between pointer and reference 
Answer :
Syntax: Pointers use * and & symbols to work with addresses, while references use the variable name directly like a normal variable.
Storage: A pointer is a separate variable that stores a memory address. A reference is just an alias (nickname) and does not have its own memory address.

 Why references cannot be reseated but pointers can
Answer : 
A pointer is like a label you can peel off one box and stick onto another. It is independent. A reference is "bonded" to the variable at the time of creation. Once it is a nickname for num, it stays a nickname for num forever. You cannot make it point to a different variable later.

 Why references cannot be NULL 
Answer :
A pointer can point to "nothing or Null. However, a reference must refer to an existing object from the moment it is created. You cannot have a nickname for nothing. This makes references safer to use than pointers.

//