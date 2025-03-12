#include<iostream>
using namespace std;
int main(){
    int a=101037500;
    int b,t=10,pro=0;
    while(a){
        int c=a%10;
        a/=10;
        pro=(pro*t)+c;       
    }cout<<pro;
}