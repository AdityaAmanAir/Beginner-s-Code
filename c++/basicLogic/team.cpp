#include<bits/stdc++.h>
using namespace std;
int main(){
int t,count=0;
cin>>t;
while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c>=2){
        count++;
    }
}cout<<count;
    return 0;
}