#include <iostream>
using namespace std;
int main(){
    int a,c=0,b=0;
    cin>>a;
    while(b<a){
        if(c%3!=0) {
            cout<<c++<<endl;
            b++;
        }else{
        c++;
        }
    }
}