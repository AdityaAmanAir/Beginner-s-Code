#include <iostream>
#include <cmath>
using namespace std;
string prime(int P){ 
    bool C=true;string ans;
    for (int i = 2; i<=sqrt(P); i++)
    {
        if (P%i==0)
        { ans = "The Number is Not Prime";
        C =false;
        break;
        }
    }if (C==true)
    {
       ans ="The Number is prime";
    }
    if (P<=1)
    {
        ans = "Negative Numbers, one and Zero are not Prime";
    }
   return (ans);
}
int main(){
    int Z;
    std::cout<<"Enter a Number : ";
    std::cin>>Z;
    std::cout<<prime(Z)<<std::endl;
    return 0;
}