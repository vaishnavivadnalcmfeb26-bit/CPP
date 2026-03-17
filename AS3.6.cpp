#include <iostream>
using namespace std;

class Vector {
private:
    int* arr;
    int size;

public:
    // Constructor
    Vector(int s) {
        size = s;
        arr = new int[size];
        // Initialize with zeros
        for (int i = 0; i < size; i++) arr[i] = 0;
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }

    // Task 3: Overloaded Subscript Operator []
    // Returns a reference so we can do v[2] = 50
    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        // Very basic error handling for beginners
        cout << "Index out of bounds!" << endl;
        return arr[0]; 
    }

    // Task 4: Overloaded Function Call Operator ()
    // Returns the sum of all elements
    int operator()() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    // Task 1: Create object
    // Aggregate initialization {1, 2, 3} isn't suitable for dynamic memory classes
    Vector v(5);

    // Task 3: Use [] to set a value
    v[2] = 50;
    v[0] = 10;

    cout << "Value at index 2: " << v[2] << endl;

    // Task 4: Use () to get the sum
    cout << "Sum of all elements: " << v() << endl;

    return 0;
}