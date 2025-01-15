#include <iostream>
using namespace std;
int bToD(int r){
    int rem,h,sum=0,pow=1;
    while (r)
    {
      rem=r%10;
      r/=10;
      h= rem*pow;  // alternate : sum+=rem*pow; ---BRUTAL
      pow*=2;
      sum+=h;
    }
    return sum;
}
int main(){
    int num;
cout<<"This program will convert the binary non-decimal number into decimal number system. Enter the Binary number : ";
   cin>>num;
   cout<<bToD(num); 
    return 0;
}