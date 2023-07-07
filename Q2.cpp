#include <iostream>
#include <vector>
using namespace std;
class Matrix {
private:
    vector<vector<int>> matrix;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows, vector<int>(cols, 0));
    }

    void setValues() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter value at position (" << i << ", " << j << "): ";
                cin >> matrix[i][j];
            }
        }
    }

    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix transpose() {
        Matrix transposed(cols, rows);

        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                transposed.matrix[i][j] = matrix[j][i];
            }
        }

        return transposed;
    }

    Matrix operator++() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ++matrix[i][j];
            }
        }

        return *this;
    }

    Matrix operator++(int) {
        Matrix temp(*this);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ++matrix[i][j];
            }
        }

        return temp;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Matrix matrix(rows, cols);

    matrix.setValues();

    cout << "Original Matrix:" << endl;
    matrix.display();

    Matrix transposed = matrix.transpose();
    cout << "Transposed Matrix:" << endl;
    transposed.display();

    ++matrix; 
    cout << "Matrix after prefix increment:" << endl;
    matrix.display();

    matrix++;  
    cout << "Matrix after postfix increment:" << endl;
    matrix.display();

    return 0;
}
