#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int k =1;
        for(int j=0;j<=i;j++){
            cout<<k++<<" ";
        }
        cout<<"\n";
    }
    return 0;
}