#include <iostream>
#include <fstream>  
#include <string>

using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    // Parameterized Constructor
    Student(int r, string n, float m) {
        roll = r;
        name = n;
        marks = m;
        cout << "Constructor: Creating student " << name << endl;
    }

    // Default constructor (Needed to create an array first)
    Student() {
        roll = 0;
        name = "";
        marks = 0.0;
    }

    // Destructor
    ~Student() {
        cout << "Destroying student " << name << "..." << endl;
    }
};

int main() {
    // Task 1: Create an array of 3 Student objects
    // Note: We assign values manually since the array was initialized with the default constructor
    Student students[3] = {
        Student(1, "Alice", 90.5),
        Student(2, "Bob", 85.0),
        Student(3, "Charlie", 92.0)
    };

    // Task 2: Write all student details to a file
    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 3; i++) {
            outFile << students[i].roll << " " << students[i].name << " " << students[i].marks << endl;
        }
        outFile.close();
        cout << "\n--- Data successfully written to file ---\n" << endl;
    }

    // Task 3: Read the file again and print contents
    ifstream inFile("students.txt");
    int r;
    string n;
    float m;

    cout << "Reading from file:" << endl;
    if (inFile.is_open()) {
        while (inFile >> r >> n >> m) {
            cout << "Roll: " << r << " | Name: " << n << " | Marks: " << m << endl;
        }
        inFile.close();
    }
    cout << endl;

    return 0;
}