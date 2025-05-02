#include<iostream>
using namespace std;
void reverseArray(int arr[], int size){
    for (int i=0;i<size/2;i++){
        swap(arr[i],arr[size-1-i]);
    }
}
int main(){
    int Myarray[11]={-2,0,1,3,9,4,1,0,10,-3,10};
    int Myarray2[11]={-2,0,1,3,-9,4,1,0,10,-3,10};
    int Myarray3[11]={-2,0,1,3,-9,4,1,-0,-10,-3,10};
    int temp;
    for (int i =0; i<11/2;i++){
        temp = Myarray[i];
        Myarray[i] = Myarray[11-1-i];
        Myarray[10-i]=temp;
    }
    for (int i=0; i<11/2; i++){
        swap(Myarray2[i],Myarray2[11-1-i]);
    }
    reverseArray(Myarray3,11);


    for (int i=0; i<11; i++){
        cout<<Myarray[i]<<" ";
    }
    cout<<endl;
    for (int i=0; i<11; i++){
        cout<<Myarray2[i]<<" ";
    }
    cout<<endl;
    for (int i=0; i<11; i++){
        cout<<Myarray3[i]<<" ";
    }
    return 0;
}