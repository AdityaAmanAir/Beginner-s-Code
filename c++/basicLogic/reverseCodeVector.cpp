#include <iostream>
#include <vector>

using namespace std;

int reverseVecPASSBYVALUE(vector <int> vec){
    int temp;
    for (int i=0; i<(vec.size()/2);i++){
        temp=vec[i];
        vec[i]=vec[vec.size()-i-1];
        vec[vec.size()-i-1]=temp;
       
    }
    for (int i : vec){
        cout<<i<<" ";
    }
    return 0;
}

int reverseVecPASSBYREF(vector <int> &vec){
    int temp;
    for (int i=0; i<(vec.size()/2);i++){
        temp=vec[i];
        vec[i]=vec[vec.size()-i-1];
        vec[vec.size()-i-1]=temp;
       
    }
    for (int i : vec){
        cout<<i<<" ";
    }
    return 0;
}

int main(){
    vector <int> vero = {1,2,3,4,5,6,7,8,9,0,-1,-2,-3};
    reverseVecPASSBYVALUE(vero);
    cout<<endl;
    for (int i : vero){
        cout<<i<<" ";
    }
    cout<<endl;
    reverseVecPASSBYREF(vero);
    cout<<endl;
    for (int i : vero){
        cout<<i<<" ";
    }
    return 0;
}