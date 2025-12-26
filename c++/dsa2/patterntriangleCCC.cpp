#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    char m = 'A';
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<m<<" ";
        }
        ++m;
        cout<<"\n";
    }
    return 0;
}