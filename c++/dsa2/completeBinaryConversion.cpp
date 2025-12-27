#include<iostream>
using namespace std;

int dec_to_bin(int a){
    int q=1,r,ans=0;
    int b=a;
    if(a<0){--a;}
    while(a){
        r=a%2;
        a/=2;
        ans+=r*q;
        q*=10;
    }
   return ans;
    if(b>=0){
        return ans;
    }else{
        int ans2=0,d=1, x=0;
        for(int i=0;i<8;i++){
             x= ans%10;
            ans/=10;
            d*=10;
            if (x==1){
                x=0;
            }else{
                x=1;
            }
            ans2+= (d*x);
        }
        return ans2;
    }
}
int main(){
    cout<<dec_to_bin(0)<<endl;
    cout<<dec_to_bin(11)<<endl;
    cout<<dec_to_bin(-11)<<endl;
    return 0;
}