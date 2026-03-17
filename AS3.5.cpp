#include <iostream>
using namespace std;

// Forward declaration of Inspector so Number knows it exists
class Inspector;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v = 0) : value(v) {}

    // Assignment Operator (=)
    void operator=(const Number& other) {
        value = other.value;
    }

    // Pre-increment (++n): Increases then returns itself
    Number& operator++() {
        value = value + 1;
        return *this;
    }

    // Post-increment (n++): Returns old value then increases
    // The (int) is just a "dummy" to distinguish it from pre-increment
    Number operator++(int) {
        Number temp = *this; // Save the old state
        value = value + 1;   // Increment
        return temp;         // Return the old state
    }

    // Friend Function declaration
    friend bool operator>(const Number& n1, const Number& n2);

    // Friend Class declaration
    friend class Inspector;
};

// Definition of Friend Function
bool operator>(const Number& n1, const Number& n2) {
    return n1.value > n2.value; // Can access private 'value'
}

// Task 2: Friend Class Inspector
class Inspector {
public:
    void print(const Number& n) {
        // Can access private 'value' because it is a friend class
        cout << "Inspector sees value: " << n.value << endl;
    }
};

int main() {
    Number n1(10), n2(20);
    Inspector spy;

    // Task 3: Compare objects using friend function
    if (n2 > n1) {
        cout << "n2 is greater than n1" << endl;
    }

    // Task 1: Show difference between pre & post increment
    cout << "\nTesting Increments:" << endl;
    Number a(5);
    
    // Pre-increment: ++a
    cout << "Using ++a: " << (++a).operator++().value; // This is a bit complex for main, 
    // let's use the Inspector to make it beginner friendly:
    
    Number b(5);
    Number c = ++b; // b becomes 6, c becomes 6
    cout << "Pre-increment result: "; spy.print(c);

    Number d(5);
    Number e = d++; // d becomes 6, e stays 5
    cout << "Post-increment result: "; spy.print(e);
    cout << "Value of d after post-increment: "; spy.print(d);

    return 0;
}