#include<iostream>
using namespace std;
int main(){
    int n=6;
    for (int i=1;i<=n;i++){
        for(int j=0; j<2*i;j++){
            cout<<"#";
        }cout<<"\n";
    }
    for (int i=0;i<n;i++){
        for(int j=2*n-i*2; j>0;j--){
            cout<<"#";
        }cout<<"\n";
    }
    return 0;
}