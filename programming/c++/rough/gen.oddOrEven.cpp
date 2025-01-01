#include <iostream>
#include <limits> // For std::numeric_limits

using namespace std;

int main() {
    int64_t Number;
    char Alphabet;

    cout << "\nThis Programme will tell you if a number is odd or even.\n\nInsert a number: ";

    if (cin >> Number) {
        // If the input was successfully read, check if it's odd or even
        if (Number % 2 == 0) {
            cout << "The number " << Number << " is EVEN.\n";
        } else {
            cout << "The number " << Number << " is ODD.\n";
        }
    } else {
        // Clear the error state and ignore the invalid input
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line

        // Now check if the next character is an alphabet
        cout << "Insert an alphabet: ";
        if (cin >> Alphabet) {
            if (isalpha(Alphabet)) {
                cout << "It is an Alphabet!\n";
            } else {
                cout << "It is not a valid alphabet!\n";
            }
        } else {
            cout << "It is not a valid input!\n";
        }
    }

    return 0;
}
