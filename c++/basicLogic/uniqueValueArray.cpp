#include <iostream>
using namespace std;
void unique(int arr[], int size){
    for (int i =0; i<size;i++){
        for (int j=i+1; j<size;j++){
            if (arr[i]==arr[j]){
            cout<<arr[i]<<"\t";
            break;
            }
        }
    }

}
int main(){
    int MyArray[11] = {-1,1,2,1,4,5,7,7,8,9,10};
    unique(MyArray,11);
    return 0;
}