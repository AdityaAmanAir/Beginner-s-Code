#include<iostream>
using namespace std;
int main (){
      int t,w=9999999;
      cin>>t;
      int count=0;
      while(t--){
         int n, k;
         cin>>n>>k;
         while (n--){
            int m;
            cin>>m;
            if (w>m){
               count++;
            }
            w=m;
         }if(count>k){
            cout<<"YES\n";
         }else{cout<<"NO\n";}
      }
   return 0;
}