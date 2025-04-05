#include<iostream>
using namespace std;
template<typename data1, typename data2> 
data1 add(data1 a, data2 b){
    return a+b;
}
int main(){

cout<< add(3.1415,7)<<endl;
cout<< add(3,7)<<endl;
cout<< add(3.1415,2.18282);
}
 