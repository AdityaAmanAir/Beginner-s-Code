#include <iostream>
using namespace std;

void printColumnMatrix(int matrix[5][1]) {
    cout << matrix[0][0] << endl;
    cout << matrix[1][0] << endl;
    cout << matrix[2][0] << endl;
    cout << matrix[3][0] << endl;
    cout << matrix[4][0] << endl;
}

int main() {
    int columnMatrix[5][1] = {
        {10},
        {20},
        {30},
        {40},
        {50}
    };

    // Print using the helper function
    printColumnMatrix(columnMatrix);

    return 0;
}