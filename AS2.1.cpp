Q1.1 Create a class Box with private members length, width, and height. 
Write: 
 A parameterized constructor 
 A function setDimensions(int, int, int) that uses this-> to distinguish between 
member variables and parameters 
 A function volume() to compute the volume 
Demonstrate: 
 Initialization using constructor 
 Assignment using setDimensions()

Answer : 

#include <iostream>
using namespace std;

class Box {
private:
    int length, width, height; // Private members

public:
    // 1. Parameterized Constructor (Initialization)
    Box(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }

    // 2. setDimensions function using 'this->' (Assignment)
    void setDimensions(int length, int width, int height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    // 3. Volume compute function
    int volume() {
        return length * width * height;
    }
};

int main() {
    // Demonstration: Initialization using constructor
    Box myBox(10, 5, 2);
    cout << "Constructor Volume: " << myBox.volume() << endl;

    // Demonstration: Assignment using setDimensions()
    myBox.setDimensions(20, 10, 5);
    cout << "Updated Volume: " << myBox.volume() << endl;

    return 0;
}


//
1.2 — Answer this: 

 Why must initialization happen before assignment? 
Answer : Initialization happens the exact moment a variable or object is created. If we don't initialize it, the variable contains Garbage Value. We initialize first to ensure the object starts in a valid and safe state before we try to use it or change its value later.

 When is initialization preferred over assignment? 
Answer : Initialization happens at the exact moment a variable is created. If we don't initialize it, the variable contains "Garbage Value" or random, useless memory data. We initialize first to ensure the object is safe to use and has a valid value from the very start.
When is initialization preferred over assignment?
For Constants (const): You cannot change a constant after it is created, so it must be initialized.
2. For References: In C++, a reference must be linked to a variable the moment it is born; it cannot be assigned later.
3. For Better Performance: Initialization is a one-step process create + set value. Assignment is a two-step process create and overwrite, which makes initialization faster and more efficient.

//