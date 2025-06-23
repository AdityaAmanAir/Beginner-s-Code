#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(){
    array <int,7> myarr ={3,-4,5,4,-1,7,-8};
    for(int st=0; st<7; st++){
        for (int end = 0; end<7; end++){
            for(int j=st; j<end;j++){
                cout<<myarr[j]<<" ";
            }cout<<"\n";
        }
    }

    return 0;
}