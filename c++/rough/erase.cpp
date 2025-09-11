#include <iostream>
#include<vector>
using namespace std;
int main(){
        int s,t=10;
        cout<<&t<<" "<<&s<<endl;
        s=10,t=20;
        cout<<&t<<" "<<&s<<endl;
        s=t;
        cout<<&t<<" "<<&s;
        
    return 0;
}