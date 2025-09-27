#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){

    for (int i=0; i<n-1;i++){
        int address=i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[address]){
                address=j;
            }
        }swap(arr[i], arr[address]);
    }

    return ;
}

void printArray(int arr[], int size, string spacingtype = " "){
    for (int i=0; i<size; i++){
    cout<<arr[i]<<spacingtype;
}
}


int main(){
int size=7;
int myarray[]={2,4,35,6,3,9,-1};
selectionSort(myarray, size);
printArray(myarray, size, "\t");
    return 0;
}