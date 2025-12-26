#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(n-j >=i){
                cout<<" ";
            }else{
                cout<<i-n+j;
            }
        }
        for(int k=i-1;k>0;k--){
            cout<<k;
        }
        cout<<"\n";
    }
    return 0;
}