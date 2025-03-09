#include <iostream>
#include <string>
using namespace std;

long long bToD(const string& binaryStr) {
    long long sum = 0;
    long long power = 1;

    // Traverse the string from the last character (right to left)
    for (int i = binaryStr.length() - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            sum += power;  // Add the current power of 2 to the sum
        }
        power *= 2;  // Move to the next power of 2
    }

    return sum;
}

int main() {
    string num;
    cout << "This program will convert the binary number into the decimal number system.\n";
    cout << "Enter the Binary number: ";
    cin >> num;

    // Call the function to convert the binary string to decimal
    cout << "The decimal equivalent is: " << bToD(num) << endl;

    return 0;
}
