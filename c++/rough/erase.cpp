#include <iostream>
using namespace std;

int b; // Global variable, default-initialized to 0

int main(int h, int g) {
    int a =11;
   double c= a/2*h*g; // Initialize local variable
    cout << c << endl;
    return 0;
}