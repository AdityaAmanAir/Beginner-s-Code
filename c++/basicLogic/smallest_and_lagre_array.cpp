#include <iostream>
using namespace std;

int main(){
    int test[11]={6,4,9,22,-2,0,7,7,10,2,-9};
    int small= -(__INT_MAX__);
    int large = __INT_MAX__;
    int len = sizeof(test)/sizeof(int);
    for (int i =0; i<len; i++){
        if (test[i]<=large){
            large = test[i];
        }
        if (test[i]>=small){
            small = test[i];
        }
    }
    cout<<"Largest Value in the array is "<<small <<" and the smallest value in the array is "<<large;

    return 0;
}