#include<iostream>
using namespace std;
int main(){
    int p;//p>3
    cin>>p;
    int x=p/2;
    //i wanted to used sqrt
    for (int i=2; i<x; ++i){
        if(p%2==0){
            cout<<"NOT Prime";
            break;
        }
    }
}