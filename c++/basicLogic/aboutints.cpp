#include <iostream>
using namespace std;
int main(){
        int a{60};
        int b(40);
        int c[20];

        cout<<a<<"\n"<<b<<"\n" <<c<<"\n"<<&c<<"\n"<<*c<<"\n"<<c[0]<<"\n"<<c[20]<<"\n";
        
    return 0;
}