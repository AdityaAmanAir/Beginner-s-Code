#include <iostream>
using namespace std;
int main(){
    int t,init=0,diff,sum=0,supersum=0;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(num>init){
            if(init==0){
                init=num;
            }else{
                diff=num-init;
                init=num;
                sum+=diff;
            }if(supersum<sum){
                supersum=sum;
            }
        
        }else{
            sum=0;
            init=num;
        }
        

    }
    cout<<supersum;
    return 0;
}