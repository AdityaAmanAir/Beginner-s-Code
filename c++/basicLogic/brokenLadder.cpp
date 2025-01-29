#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,k,b=0;
    bool o=true;
    cin>>t>>k;
    while(t--){

        int a;
        cin>>a;
        if((a-b)>k){ 
            o=false;
        }else{
        b=a;
    }
   
    } if(o==true){
            cout<<"YES";}
            else{
cout<<"NO";
            }

    return 0;
}