#include <iostream>
#include <cstring> 
using namespace std;

class String {
    char* str;

public:
    // 1. Constructor
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // 2. Copy Constructor (Deep Copy)
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        cout << "[System] Deep Copy performed" << endl;
    }

    // 3. Destructor
    ~String() {
        delete[] str;
    }

    // 4. Assignment Operator
    String& operator=(const String& other) {
        if (this != &other) { // Avoid self-assignment
            delete[] str;     // Delete old memory
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // 5. Operator+ for Concatenation
    String operator+(const String& other) {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        
        String result(temp);
        delete[] temp; // Clean up local temporary pointer
        return result;
    }

    // 6. Overloading << and >>
    friend ostream& operator<<(ostream& out, const String& s) {
        out << s.str;
        return out;
    }

    friend istream& operator>>(istream& in, String& s) {
        char buffer[100]; // Temporary buffer for input
        in >> buffer;
        delete[] s.str;
        s.str = new char[strlen(buffer) + 1];
        strcpy(s.str, buffer);
        return in;
    }
};

int main() {
    // Task 1: Input two strings
    String s1, s2;
    cout << "Enter first word: "; cin >> s1;
    cout << "Enter second word: "; cin >> s2;

    // Task 2: Concatenate
    String s3 = s1 + s2;

    // Task 3: Print all three
    cout << "\nString 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Combined (String 3): " << s3 << endl;

    // Task 4: Demonstrate Deep Copy
    cout << "\nCreating s4 as a copy of s1..." << endl;
    String s4 = s1; 
    cout << "s4 value: " << s4 << endl;

    return 0;
}