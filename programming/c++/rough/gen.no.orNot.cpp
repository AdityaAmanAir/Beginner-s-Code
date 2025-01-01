#include <iostream>
#include <limits> // For std::numeric_limits

using namespace std;

int main() {
    int64_t Number;
    std::cout << "\nThis Programme will tell you if a number is odd or even.\n\nInsert a number: ";

    // Try to read the input
    if (cin >> Number) {
        // If the input was successfully read, check if it's odd or even
        if (Number % 2 == 0) {
            cout << "The number " << Number << " is EVEN.\n";
        } else {
            cout << "The number " << Number << " is ODD.\n";
        }
    } else {
        // If the input was not a number, clear the error state and ignore the invalid input
        cout << "It is not a number!\n";
        cin.clear(); // Clear the error flag
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
    }

    return 0;
}
