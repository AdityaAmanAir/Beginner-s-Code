#include<iostream>
using namespace std;
void fibonacci(int N){
int A=0, B=1;
if (N!=1)
{
    for(int i=1; i < (N/2); i++)
{
    A+=B;
    B+=A;
}
if (N%2==0)
{ 
    cout<<B;
}
else
{
    cout<<A+B;
}
}else{cout<<"0";}
}
int main (){int num;
cout<< "Enter the the nth term for which you need to find the Fibonnci Number : ";
cin>>num;
fibonacci(num);
    return 0;
}