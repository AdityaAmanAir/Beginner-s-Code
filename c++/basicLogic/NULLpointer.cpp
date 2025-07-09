#include <iostream>
using namespace std;
int main(){
    int* p = NULL;
    cout<<p;
    //cout<<*p; //This will give Segmentation Fault error ... Because we are trying to access those memomy which is not allowed ;
    return 0;
}