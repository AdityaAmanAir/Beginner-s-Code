#include<iostream>
int main(){
    int a,b=0;
    std::cin>>a;
    for (int i=1; i<=a;++i){
        b+=i;
    }
    std::cout<<b;
}