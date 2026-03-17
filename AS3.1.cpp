#include <iostream>
#include <string>

class Employee {
public:
    int id;
    std::string* name; // Using a pointer to demonstrate deep copy
    mutable int accessCount;

    // Standard Constructor
    Employee(int i, std::string n) {
        id = i;
        name = new std::string(n); // Allocate memory
        accessCount = 0;
    }

    // User-defined Copy Constructor (Deep Copy)
    Employee(const Employee& other) {
        id = other.id;
        // Deep copy: Create a NEW memory location and copy the value
        name = new std::string(*(other.name)); 
        accessCount = other.accessCount;
        std::cout << "[Copy Constructor Called] Deep copy performed.\n";
    }

    // Destructor to clean up memory
    ~Employee() {
        delete name;
    }

    // Const member function
    void display() const {
        accessCount++; // Possible only because accessCount is 'mutable'
        std::cout << "ID: " << id << " | Name: " << *name 
                  << " | Accessed: " << accessCount << " times" << std::endl;
    }
};

int main() {
    // Task 1: Create e1 and call display multiple times
    Employee e1(101, "Alice");
    e1.display();
    e1.display();

    // Task 2: Create e2 = e1 (This triggers the copy constructor)
    Employee e2 = e1; 

    // Prove it's a Deep Copy
    std::cout << "\n--- Proving Deep Copy ---" << std::endl;
    std::cout << "e1 Name Address: " << e1.name << std::endl;
    std::cout << "e2 Name Address: " << e2.name << std::endl;

    if (e1.name != e2.name) {
        std::cout << "Success: Addresses are different. This is a Deep Copy." << std::endl;
    } else {
        std::cout << "Warning: Addresses are the same. This is a Shallow Copy." << std::endl;
    }

    return 0;
}