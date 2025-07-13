#include <iostream>
using namespace std;

void modify(int& x) {  // '&' means reference
    x = 20;  // Changes the original variable
    cout << "Inside function (modified x): " << x << endl;
}

int main() {
    int a=-1;
    int b =0, c=1;
    if(a){
        cout<<a;
    }
    if(b){
        cout<<b;
    }
    if(c){
        cout<<c;
    }
}