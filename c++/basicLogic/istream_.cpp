#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: "; // Prompt user
    cin >> age;                 // Read input into variable
    cout << "You are " << age << " years old." << endl;

    cerr;// Error mess
    clog << "Log: Program executed." << endl;       // Log message
    return 0;
}