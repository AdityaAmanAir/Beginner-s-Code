#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool isSwap = false;
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
                isSwap =true;
            }
        }
        if(isSwap==false){
            return;
        }
    }
}


int main(){
int size=7;
int myarray[]={2,4,35,6,3,9,-1};
bubbleSort(myarray, size);
for (int i=0; i<size; i++){
    cout<<myarray[i]<<"\t";
}

    return 0;
}