#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int x=0;
    while(n){
        x=n;
        n=n>>2;
        n=n<<2;
        if(n==x){
            n=n>>2;
        }else {
            if(n==0){
                cout<<"yes power";
                return 0;
            }else{
                cout<<"NO power";
                return 0;
            }
        }
    }
}