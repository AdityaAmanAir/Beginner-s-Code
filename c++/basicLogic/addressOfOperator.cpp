#include <iostream>
using namespace std;
int main(){
    int a =10;
    int* p = &a;
    cout<<a<<endl;
    cout<<&a<<endl<<endl;

    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl<<endl;
    //cout<<*a<<endl;//this will show error because it in not pointer
int* p2 =p;
    cout<<p2<<endl;
    cout<<*p2<<endl;
    cout<<&p2<<endl<<endl;

int** p3 =&p;
    cout<<p3<<endl;
    cout<<*p3<<endl;
    cout<<**p3<<endl;
    //cout<<***p3<<endl; *** do not contain any address
    cout<<&p3<<endl<<endl;


    int*** p4 =&p3;
    cout<<p4<<endl;
    cout<<*p4<<endl;
    cout<<**p4<<endl;
    cout<<***p4<<endl; 
    cout<<&p4<<endl<<endl;
    return 0;
}