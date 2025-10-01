#include<iostream>
#include<array>
using namespace std;
int main(){
int a[999999999]={1,2,3,4,5};
array <int, 5> b={1,2,3,4,5};

for(int i=0; i<11;i++){
    cout<<a[i]<<" "<<&a[i]<<endl;
    cout<<b[i]<<" "<<&b[i]<<endl;
}



    return 0;
}