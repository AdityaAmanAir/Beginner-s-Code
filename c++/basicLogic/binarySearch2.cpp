#include <iostream>
#include <vector>
// using namespace std;
int main(){
    std::vector <int> arr={0,1,2,3,5,7,10,15,29,54,64,127};
    int target =-1;

    int end = sizeof(arr)-1;
    int st =0;
    int mid=1;
    bool not_found = true;

    while(st<=end){
        mid=st +(end-st)/2;
        if (arr[mid]<target){
            st = mid+1;
        }else if (target<arr[mid]){
            end = mid-1;
        }else if (arr[mid]==target){
            std::cout<<"Present at index "<<mid;
            not_found=false;
            break;
        }
    }if(not_found==true){
        std::cout<<"Not found -1";
    }

}