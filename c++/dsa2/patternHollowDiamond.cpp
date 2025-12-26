#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            cout<<" ";
        }
        cout<<"* ";
        for(int k=3;k<=2*i;k=k+2){
            cout<<"  ";
        }
        if(i>0){
        cout<<"*";}
        cout<<"\n";
    }
    int t=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        if(i<n-1){
            cout<<"*";
        }
        for(int k=n-i+2;k>t;k--){
            cout<<" ";
        }
        t=t+1;
        cout<<"*\n";
    }

    return 0;
}