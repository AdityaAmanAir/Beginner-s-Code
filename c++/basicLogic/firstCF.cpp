#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,c,d,e=1;
        cin>>a;
        c=a/15;
        d=a%15;
        if(d>=2){
            e=3;
        }else if(d==1){
            e=2;
        }cout<<c*3+e<<"\n";
    }
        return 0;
}
    