#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
    int a;
    cin>>a;
    int sum=0,check=0,zero=0;
    bool z=false;
    while(a--){
        int x;
        cin>>x;
        if(x==0){
            z=true;
            zero++;
            check++;
        }
        if(z==true && x<3){
            if(x==check && a!=0){
                check++;
            }else if(x<check && a!=0){
                sum+=1;
                z=false;
            }else if(x==check && a==0){
                check++;
                sum+=(x*(x+1)/2);
            }else if(x<check && a==0){
                sum+=1;
                sum+=(x*(x+1)/2);  
                z=false;
            }else if(x>check ){
                sum+=check;
                z=false;
            }
        }
        if(z==false || x>=4){
            sum+=x;
        
        }
    }
    if(zero>1){
        zero=zero-1;
    }else{
        zero=0;
    }
    cout<<sum-zero<<"\n";
   }
return 0;
}