#include <iostream>
using namespace std;
int sum =0;
int main(){

    cout<<"This programme will calculate the sum and product of all the numberes in an array.";
    int Myarray[11]={-1,1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(Myarray)/sizeof(int);
    int pro=1;
    for (int i=0;i<len;i++){
        sum+=Myarray[i];
        pro*=Myarray[i];
    }
    cout<<sum<<"\n"<<pro;

    return 0;
}