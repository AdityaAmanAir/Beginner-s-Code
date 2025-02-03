#include <iostream>
using namespace std;

int bintod(int c){
    int e,f,dum=0;
    int g=1,pro;
    while(c){
        e = c%10;
        pro=e*g;
        dum+=pro;
        c/=10; 
        g*=2;    
    }
    return dum;
}

int main(){
    
    int a,b,sum,o,p,g=1,lol,job=0;
    cin>>a>>b;
   int x;
   x= bintod(a);
    int y;
    y =bintod(b);
    sum =x+y;
   
    while(sum){
        o=sum%2;
        lol=o*g;
        g*=10;
        sum/=2;
        job+=lol;
        
    }
    cout<<job;
    return 0;
}