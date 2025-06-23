#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main(){
    vector <int> myVector = {1,2,3,4,5};
    int n=5;
    array <int,5> myarray = {1,2,3,4,5};

    for (int a =0 ; a< n; a++){
        for(int i =a; i<n; i++){
            for(int j=a; j<i;j++){
                cout<< myarray[j];
            }cout<<" ";        
        }cout<<"\n";
    }

    for (int a =0 ; a< n; a++){
        for(int i =a; i<n; i++){
            for(int j=a; j<i;j++){
                cout<< myVector[j];
            }cout<<" ";        
        }cout<<"\n";
    }


    return 0;
}