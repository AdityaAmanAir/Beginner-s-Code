#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    double a,b;
    cin>>a>>b;
    b=(cbrt(b));
    b/=2.0;
    a=cbrt(((3.0/4.0)*a/(3.1415926)));
    cout<<((a<=b)? "YES" : "No");
    
}