#include <iostream>
using namespace std;
int main(){
    int test[11]={6,4,9,22,-2,0,7,7,10,2,-9};
    int small= -(__INT_MAX__);
    int large = __INT_MAX__;
int len = sizeof(test)/sizeof(int);
int smallIndex =-1;
int largeIndex=-1;
    for (int i=0; i<len;i++){
        if (test[i]<=large){
            large = test[i]  ;
        largeIndex =i;  }
        if (test[i]>=small){
            small = test[i]  ;
        smallIndex =i;  }
    }
cout<<"Largest Value in the array is "<<small <<" and the smallest value in the array is "<<large;
cout<<endl<<"Largest Value is at index "<<largeIndex <<" and the smallest value is at index "<<smallIndex;

    return 0;
}