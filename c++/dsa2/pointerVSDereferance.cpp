#include<iostream>
using namespace std;
int main(){
    int a=10;
    int* p = &a;
    *p=20;
    
    cout<<p<<endl<<&a<<endl<<*p<<endl<<a<< endl ;
        int&  b=a;
        int x =a;
        a =50;
        cout<<a<<endl<<b<<endl<<x;


        int* l=&a;
        double ff=0.69;
        double* f =&ff;
        cout<<endl<<endl<<l<< "    "<<f<<endl;
        cout<<++l<< "    "<<++f<<endl;
        cout<<++l<< "    "<<++f<<endl;
        cout<<++l<< "    "<<++f<<endl;
        cout<<++l<< "    "<<++f<<endl;
        cout<<++l<< "    "<<++f<<endl;
        cout<<++l<< "    "<<++f<<endl;

    return 0;
}