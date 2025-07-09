#include <vector>
#include <iostream>
using namespace std;


void change(int &b){ //pass by reference using alias
    b=20;
    // return 0;
}

void change2(int* p){ // pass by referance using pointers
    *p=30;

}


int main(){
    int a=10;
    change(a);
    cout <<a<<endl;

    change2(&a);
    cout <<a;
return 0;
}