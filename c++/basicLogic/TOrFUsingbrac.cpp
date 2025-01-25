#include <iostream>
using namespace std;

int main() {
    int num = 15;
    cout << ((num % 2 == 1) ? "LOL True": 1) << endl; //Both options in a ternary operator must be of the same type, or the compiler won't know how to handle them. 😊
    return 0;
}
