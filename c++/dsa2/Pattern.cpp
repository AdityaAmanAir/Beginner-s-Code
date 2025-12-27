#include<iostream>
using namespace std;
int main(){
    int n=10;
    for (int i=0;i<n;i++){
        for(int j=0;j<i*2+1;j++){
            cout<<"#";
        }for(int j=0;j<2*(n-i)-1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}