// #include <iostream>
// using namespace std;
// int main(){
//     int t,add=0;
//     cin>>t;
//     int h=t;
//     for(int j=1;j<=h;j++){int f=1,pro=1;
//     for(int i=1;i<=t;i++){
//         pro*=f;
//         ++f;
//         }t--;
//         add+=pro;
//     }cout<<add;
//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    int t,pro=1,s=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        pro*=i;
        s+=pro;
    }cout<<s;
    return 0;
}