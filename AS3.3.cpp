#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int** mat; // Pointer to pointer for 2D array

public:
    // Constructor to allocate memory
    Matrix(int r, int c) : rows(r), cols(c) {
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }
    }

    // Task 4: Destructor to deallocate memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i]; // Delete each row
        }
        delete[] mat; // Delete the array of pointers
    }

    // Task 1: Overload >> for input
    friend istream& operator>>(istream& in, Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                in >> m.mat[i][j];
            }
        }
        return in;
    }

    // Task 1: Overload << for display
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                out << m.mat[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Task 2: Overload + for addition
    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Task 3: Overload == for comparison
    bool operator==(const Matrix& other) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (this->mat[i][j] != other.mat[i][j]) {
                    return false; // Found a mismatch
                }
            }
        }
        return true; // All elements matched
    }
};

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Matrix m1(r, c), m2(r, c);

    cout << "Enter elements for Matrix 1:" << endl;
    cin >> m1;
    cout << "Enter elements for Matrix 2:" << endl;
    cin >> m2;

    // Addition
    Matrix m3 = m1 + m2;
    cout << "\nSum (m1 + m2):\n" << m3;

    // Comparison
    if (m1 == m2) {
        cout << "\nMatrices are equal." << endl;
    } else {
        cout << "\nMatrices are not equal." << endl;
    }

    return 0;
}