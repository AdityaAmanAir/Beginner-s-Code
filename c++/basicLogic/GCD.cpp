#include<iostream>
using namespace std;
int main(){
    int x,y;
    bool n= true;
    cin>>x>>y;
    //int x,y;
        //((a<=b)? (x=a,y=b):(x=b,y=a));
    while(x!=0){
        int h=y%x;
        y=x;
        x=h;
        }cout<<y;
    return 0;
}