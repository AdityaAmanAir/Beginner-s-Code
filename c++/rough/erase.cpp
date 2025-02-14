#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double a,b,m,n,x;
    cin>>m>>a>>n>>b;
    x=(b-a)/(m-n);
    cout<<setprecision(16)<<x;
    return 0;
}