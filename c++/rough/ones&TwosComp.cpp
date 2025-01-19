#include <iostream>
using namespace std;
int main(){
    cout<<"This programm will convet the number using one's compliment. That is it will perform one's compliment : ";
    int x;
    cin>> x;
    x =~x;
    cout<<"One's compliment:" << x<< "\nTwo's compliment:"<< x+1;
    return 0;
}