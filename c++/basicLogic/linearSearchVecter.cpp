#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector <int> vec,int num){
    bool t= true;
    for (int i=0; i<vec.size();i++){
        if(num== vec[i]){
            return i;
        }
    }return -1;
}

int main(){
    vector <int> vero = {1,2,3,4,5,6,7,9,0,-1,1,2,3};
    int num =9;
    cout<<linearSearch(vero,num);
    return 0;
}