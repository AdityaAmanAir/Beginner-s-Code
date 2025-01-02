#include <iostream>
using namespace std;

int main() {
    int dimension;
    cout << "This program will form the pattern, starting from the alphabet A.\nEnter the dimension of the square: ";
    cin >> dimension;

    char currentChar = 'A'; // Start from 'A'

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << currentChar << " ";

            // Increment the character
            currentChar++;

            // If it exceeds 'Z', wrap around to 'A'
            if (currentChar > 'Z') {
                currentChar = 'A';
            }
        }
        cout << "\n"; // New line after each row
    }

    return 0;
}
