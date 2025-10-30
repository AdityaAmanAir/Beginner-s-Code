#include <iostream>
int main(){

    char x[]="color";
    char y[]="color";
    std::cout<<&x<<"\t"<<y[-4]<<"\t"<<&y;

    for(int i=0;i<=100;i++){
        std::cout<<x<<std::endl;
    }

    for (int i=0;i>=-100;i--){
    std::cout<<&y[i]<<std::endl;
    }

    return 0;
}