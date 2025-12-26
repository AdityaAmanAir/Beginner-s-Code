#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int c=65+n;
for(int i=0; i<n;++i){
    for(int j =65; j<c;j++){
        cout<<((char)j);
    }
    cout<<"\n";
}


}