#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a=5;
    int b=12;
    //int c=&a;
    //int d=*a;
    int &e=b;
    //int *f=b;
    int *g=&a;
cout<<a<<endl<<b<<endl<<e<<endl<<g<<endl<<&e<<endl<<*g;

    return 0;
}