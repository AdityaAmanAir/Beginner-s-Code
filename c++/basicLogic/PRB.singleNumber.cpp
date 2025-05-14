#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <int> vec ={3,3,2,12,2};
    int sum=0;
    for (int i : vec){
        sum=sum^i;
    }
    cout<<sum;
   
    return 0;
}