#include<iostream>
using namespace std;
int main(){
    int a,p=1;
    cin>>a;
    for(int i=2;i<=a;i++){
        p*=i;
    }
    cout<<p;
    return 0;
}