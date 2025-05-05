#include <iostream>
using namespace std;

void intersection(int arr1[], int size1, int arr2[], int size2){
    for (int i=0; i<size1; i++ ){
        for (int j=0; j<size2; j++){
            if (arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
            }
        }
    }
}

int main(){
    int Myarray1[8]={1,2,3,3,4,4,5,6};
    int Myarray2[9]={0,1,2,9,11,4,5,13,0};
    intersection(Myarray1,8,Myarray2,9);

    return 0;
}