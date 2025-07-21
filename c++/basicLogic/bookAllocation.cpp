#include <iostream>
#include <vector>
// using namespace std;

bool isValid(std::vector <int> &arr, int n , int m, int maxAllowedPages){
    int sum =0;
    int count=0;
    for(int i : arr){
        sum+=i;
        if(sum>maxAllowedPages){
            count++;
            sum=i;
        }
        
    }
    if(count>n){
        return false;
    }else{
        return true;
    }
}

int thisFunction(std::vector <int> &arr, int n, int m){
    if(m<n){
        return -1;
    }
    

    int end=0;
    for(int i : arr){
        end+=i;
    }
    // std::cout<<end;
    int ans=-1;
    int st=0;
    int mid;
    while (st<=end){
        mid =st+(end-st)/2;
        if(isValid( arr,  n,  m,  mid)){
            ans = mid;
            end=mid-1;
        }else{
            st=mid+1;
        }

    }


    return ans;
}



int main(){
    std::vector <int> arr={15,17,20};
    std::cout<<thisFunction(arr, 4,2);
    return 0;
}