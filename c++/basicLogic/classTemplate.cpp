#include<iostream>
using namespace std;

template<typename data1>
class A{
        data1 V;
    public:
        data1 sq(data1 a){
            V=a*a;
    return V;
}
};
int main(){
    A<float> obj;
    cout<<"Square of 3.1415 is "<<obj.sq(3.1415)<<"\n";
    cout<<"Square of 3 is "<<obj.sq(3)<<endl;
    return 0;
}