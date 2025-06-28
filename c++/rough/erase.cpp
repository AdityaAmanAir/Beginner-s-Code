#include <iostream>
using namespace std;

void modify(int& x) {  // '&' means reference
    x = 20;  // Changes the original variable
    cout << "Inside function (modified x): " << x << endl;
}

int main() {
    int num = 10;
    modify(num);
    cout << "Outside function (original num): " << num << endl;
    return 0;
}