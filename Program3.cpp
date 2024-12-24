//   Program to read two 3x3 matrices and add them

#include <iostream>

using namespace std;

int main() {
    int matrix1[3][3], matrix2[3][3], result[3][3];

    // Input elements for matrix1
    cout << "Enter elements of matrix 1:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements for matrix2
    cout << "Enter elements of matrix 2:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Add matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the result matrix
    cout << "\nResultant Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
