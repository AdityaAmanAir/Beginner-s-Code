#include <bits/stdc++.h>
using namespace std;
bool isInteger(double x) {
    return floor(x) == x;
}
int main() {
	double a,b,d;
	cin>>a>>b;
	d=(sqrt((a*a)-(b*b)))+b;
	if (isInteger(d)) {
        cout << fixed << setprecision(1) << d;  
    } else {
        cout << fixed << setprecision(15) << d; 
    }
}