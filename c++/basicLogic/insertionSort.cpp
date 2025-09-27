#include<iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i=1; i<size;i++){
        int val=arr[i];
        for(int j=i-1; j>=0;j--){
            if(arr[j]>val){
                arr[j+1]=arr[j];
                arr[j]=val;
            }else{
                arr[j+1]=val;
                break;
            }
        }
    }
}

void printArray(int arr[], int size, string spacingtype = " "){
    for (int i=0; i<size; i++){
    cout<<arr[i]<<spacingtype;
}
}

int main(){

int size=7;
int myarray[]={2,4,35,6,3,9,-1};
insertionSort(myarray, size);
printArray(myarray, size, "\t");

    return 0;
}