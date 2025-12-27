#include<iostream>
using namespace std;
int binarySearch(int arr[],int len, int finding){
    // int len =sizeof(arr[])/sizeof(int);
    int st=0, end=len;
    int mid;
    while(st<=end){
        mid=(st +end)/2;
        if(arr[mid]>finding){
            end=mid-1;
        }else if(arr[mid]<finding){
            st=mid+1;
        }else if(arr[mid]==finding){
            return mid;
        }
    }return -1;

}

int main(){
    int a[]={1,2,3,4,5,6,7,8};
    cout<<binarySearch(a,8, 8)<<endl;
    cout<<binarySearch(a,8, 7)<<endl;
    cout<<binarySearch(a,8, 6)<<endl;
    cout<<binarySearch(a,8, 5)<<endl;
    cout<<binarySearch(a,8, 4)<<endl;
    cout<<binarySearch(a,8, 3)<<endl;
    cout<<binarySearch(a,8, 2)<<endl;
    cout<<binarySearch(a,8, 1)<<endl;
    cout<<binarySearch(a,8, 0)<<endl;
    cout<<binarySearch(a,8, 10)<<endl;
cout<<binarySearch(a,8, -10)<<endl;


}