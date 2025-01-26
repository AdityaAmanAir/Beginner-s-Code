#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,prod=1;
    cin>>t;
    while(t--){
        int a;
        int b;
        int diff;
        cin>>a>>b;
        diff=b-a+1;
        prod*=diff;
    }
    cout<<prod;
    return 0;
}