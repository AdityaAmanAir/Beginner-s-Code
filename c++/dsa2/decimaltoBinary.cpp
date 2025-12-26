#include<iostream>
using namespace std;

int convertDectToBinary(int a){
    int q=1,r,ans=0;
    while(a){
        r=a%2;
        a/=2;
        ans+=r*q;
        q*=10;
    }return ans;
}

int binToDec(int a){
    int ans=0;
    int p=1,d=0;
    while(a){
        d=a%10;
        ans+=d*p;
        p*=2;
        a/=10;
    }
    return ans;
}

int main(){
cout<<binToDec(convertDectToBinary(0))<<endl;
for(int i=0; i<100; i++){
    cout << convertDectToBinary(i) <<" "<<convertDectToBinary(-i)<<endl;
}
}