#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector <int> arr,int target, int start  , int end ){
    if (start<=end){
        int mid = start+(end-start)/2;
        if (arr[mid]<target){
            return (binarySearch(arr, target , start = mid+1,  end ));
        }else if(target<arr[mid]){
                return binarySearch(arr, target , start , end =mid-1 );
        }else {
            return mid;
        // }else{
        //     return -1;
        }
    }
   return -1;
}


int main(){
    vector <int> myArray={1,2,3,4,6,7,8,9,10};
    int target =15;
    cout<<binarySearch(myArray, target,0,myArray.size());

    return 0;
}