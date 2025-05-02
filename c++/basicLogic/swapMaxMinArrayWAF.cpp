#include<iostream>
using namespace std;
void swapMax(int arr[], int size){
    int inf=__INT_MAX__, _inf=-__INT_MAX__;
    int min =__INT_MAX__, max=__INT_MAX__;
    for (int i =0; i<size;i++){
        if(arr[i]<=inf){
            inf=arr[i];
            min=i;
        }
        if(arr[i]>=_inf){
            _inf=arr[i];
            max=i;
        }
    }swap(arr[min],arr[max]);

}
int main(){
    int Myarray[11]={-1,1,99,3,4,5,6,-7,8,9,10};
    int len = sizeof(Myarray)/sizeof(int);
    swapMax(Myarray, 11);
    for (int i=0; i<len; i++){
         cout<<Myarray[i]<<" ";
    }
    return 0;
}