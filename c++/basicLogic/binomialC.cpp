#include <iostream>
using namespace std;
long int facto(int F){
    long int factor=1;
    for (int i = 1; i <= F; i++)
    {
        factor *=i;
    }
    return factor;
}
int main(){
    int n,r;
    cout<< "This program will find the the binomial cofficent of the expression. \n Enter the positions (n & r respectively) of the term :";
    cin>>n>>r;
    cout<<"The Bionmial coefficent of the term is "<< facto(n)/((facto(r))*(facto(n-r)));
    return 0;
}