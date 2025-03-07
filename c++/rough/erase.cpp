#include <iostream>
using namespace std;
int main() {
    int a;
    cin>>a;
    while(a%2==0){
        a/=2;
    }while(a%3==0) a/=3;
    cout<<((a==1)?"YES":"NO");
   return 0;
}