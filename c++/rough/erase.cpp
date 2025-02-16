#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b;
    int n=0;
    while(pow(2,n)<=b){
        ++n;
    }
if(pow(2,--n)>=a){
    cout<<setprecision(33)<<pow(2,n);
}else{
    cout<<-1;
}
}