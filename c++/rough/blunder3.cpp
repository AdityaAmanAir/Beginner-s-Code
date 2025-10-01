#include <iostream>
using namespace std;

int main() {
    float f = 0.7f; //0.7 is float i.e  0.699999988079071045
    if (f==0.7){
        cout<<"yes"<<endl;
    }else{cout<<"No 0.7 "<<0.7<<" "<<f<<endl;}
    if (f==0.699999988079071045){
        cout<<"yes f==0.699999988079071045 "<<endl;
    }

    double ff = 0.7; //0.7 is double
    if (ff==0.7){
        cout<<"yes";
    }else{cout<<"No 0.7 "<<0.7<<" "<<ff;}


    return 0;
}