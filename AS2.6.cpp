Q6.1 Create a class Employee with: 
 const int employeeId 
 string name 
 float salary 
Write a constructor using initializer list to initialize all members. 

Answer :

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    // These are the data members
    const int employeeId; 
    string name;
    float salary;

public:
    //  Constructor using an Initializer List
    // The colon (:) starts the list, and we map parameters to members
    Employee(int id, string n, float s) : employeeId(id), name(n), salary(s) {
        // Body is empty because members are initialized before the body starts
        cout << "Constructor: Members initialized using list." << endl;
    }
};

int main() {
    // Creating an object to test the constructor
    Employee emp(501, "Suresh", 60000.0);
    
    return 0;
}

Q6.2 — Add a function to display details. 
Answer :
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    const int employeeId;
    string name;
    float salary;

public:
    // Constructor using initializer list
    Employee(int id, string n, float s) : employeeId(id), name(n), salary(s) {
    }

    // Function to display details
    void display() {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Creating an object and passing values
    Employee emp(101, "Aryan", 55000.0);
    
    // Calling the display function
    emp.display();

    return 0;
}

//
Q6.3 — Answer these: 
1. Why must const members be initialized in initializer list? 
Answer :
Because const members are "read-only," they must be given a value at the exact moment they are created.
The initializer list handles this creation (initialization). By the time the code reaches the constructor body { }, the variable is already created, and any attempt to give it a value is seen as an "update" (assignment), which is blocked for const variables.

2. What happens if you try to assign the value of a const member inside constructor body? 
Answer :
If we try to assign a value to a const member inside the constructor body { }, the compiler will throw an error. This is because const variables must be initialized at the moment they are created. In C++, by the time the constructor body starts, the members are already created. Trying to give them a value there is seen as an assignment (changing an existing value), which is forbidden for const types.

3. Why is initializer list faster than assignment?
Answer :
It is faster because it avoids double work.
Initializer List: The member is created and given a value in one single step.
Assignment: The member is first created with a "default" value, and then it is updated with your value inside the { } body. This is two steps.

//