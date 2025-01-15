#include <iostream>
#include <cmath>
using namespace std;
int dtob (int num) {
    int q,r=0,x=0,t=1;
    while (num!=0){q=num%2;
    num/=2;
    r=(q*(t))+r;
    t*=10;
    }
    return r; //binary form
}
int main(){
int n;
    cout<<"This programm will convert decimal to binary number. Enter the base 10 number : ";
    cin>>n;
    cout<<dtob(n);
    return 0;
}