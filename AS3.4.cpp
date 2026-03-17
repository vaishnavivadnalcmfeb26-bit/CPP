#include <iostream>
using namespace std;

// 1. Custom Exception Class
class DivideByZero {};

// 3. Function with exception specification list
// This tells the compiler: "This function might throw a DivideByZero error"
double divide(int a, int b) throw(DivideByZero) {
    if (b == 0) {
        throw DivideByZero(); // Throwing our custom error
    }
    return (double)a / b;
}

int main() {
    int num, den;
    cout << "Enter numerator and denominator: ";
    cin >> num >> den;

    // 2. Nested try-catch block
    try {
        // Outer Try
        try {
            // Inner Try
            double result = divide(num, den);
            cout << "Result: " << result << endl;
        } 
        catch (DivideByZero) {
            // Inner Catch
            cout << "Inside inner catch" << endl;
            throw; // Rethrows the exception to the outer catch
        }
    } 
    catch (DivideByZero) {
        // Outer Catch
        cout << "Handled in outer catch" << endl;
    }

    return 0;
}