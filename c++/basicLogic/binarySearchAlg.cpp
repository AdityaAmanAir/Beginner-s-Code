#include <iostream>
using namespace std;

int main(){
   int arr[]={-2,-1,0,4,6,17,133,525,1024,2025};
    int target=269;
    int len=10;
    int st=0, end=len;
    int found =-2;
    int mid;
    int x=(len/2+1);
    while(x--){
        mid = (st+end)/2;
        if(arr[mid]==target){
            found = mid;

        }else if(arr[mid]<target){
            st=mid;
        }else{
            end=mid;
        }

    }cout<<found+1;

    return found; 
}