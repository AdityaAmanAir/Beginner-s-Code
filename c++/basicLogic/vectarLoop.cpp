#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> verr={1,2,3,4,5,6};
    for (int i : verr){
        cout<<i<<"\n";
    }

    vector <char> verr2={'A','B','C','D','E','F','G','H','I','J'};
    for (char val : verr2){
        cout<<val<<"\t";
    }
    return 0;
}