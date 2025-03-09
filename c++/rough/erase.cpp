#include <iostream>
using namespace std;
long long int bas(int a){
    long long int t=1,pro=0;
    while(a){
        long long int c=a%4;
        pro+=(c*t);
        t*=10;
        a/=4;
    }
    return pro;
}
long long int rev(int b){
    long long int pro=0,t=1;
    while(b){
    long long int c=b%10;
    pro+=(c*t);
        t*=4;
        b/=10;
    }
    return pro;
}

int main(){
    long long int a,b,c;
    cin>>a>>b;
    a=bas(a);
    b=bas(b);
    c=a+b;
    long long int e=0,t=1;
    while(c){
        long long int d=c%10;
        if(d>=4) d-=4;
        e+=(d*t);
        t*=10;
        c/=10;
    }cout<<rev(e);
    return 0;
}