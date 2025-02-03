#include <iostream>
using namespace std;

int main(){
    int c;
    cin>>c;
    int e,f,dum=0;
    int g=1,pro;
    while(c){
        e = c%10;
        pro=e*g;
        dum+=pro;
        c/=10; 
        g*=2;
         
    }
   cout<<dum;
    return dum;
}