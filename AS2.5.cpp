Q5.1 Create a class Student with: 
 rollNo 
 name 
 marks 
Write the following: 
1. Default constructor 
2. Parameterized constructor 
3. Constructor that uses this-> pointer 
4. A function to print student details 
Create: 
 One object using default constructor 
 Two objects using parameterized constructor 

Answer : 

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    // 1. Default Constructor
    Student() {
        rollNo = 0;
        name = "Unknown";
        marks = 0.0;
        cout << "Default Constructor called!" << endl;
    }

    // 2. Parameterized Constructor
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        cout << "Parameterized Constructor called!" << endl;
    }

    // 3. Constructor using 'this->' pointer
    // Used when parameter names are the same as class member names
    Student(int rollNo, string name) {
        this->rollNo = rollNo;
        this->name = name;
        this->marks = 0.0; 
        cout << "Constructor with 'this->' called!" << endl;
    }

    // 4. Function to print student details
    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    // Creating one object using default constructor
    Student s1;
    s1.display();

    // Creating two objects using parameterized constructor
    Student s2(101, "Alice", 85.5);
    Student s3(102, "Bob", 92.0);

    s2.display();
    s3.display();

    return 0;
}

//
Q5.2 — Answer: 
 When does compiler generate a default constructor? 
Answer :
The compiler automatically creates a default constructor only if you do not write any constructor at all in your class.

 When does it NOT generate one? 
Answer :
If you write any constructor like a parameterized one, the compiler stops providing the automatic default constructor. You must then write your own if you still need it.
 
 Can constructors be overloaded?
Answer :
We can have multiple constructors in the same class as long as they take different types or a different number of inputs. This lets you create objects in different ways.
//