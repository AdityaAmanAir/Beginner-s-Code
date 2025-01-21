#include <iostream>
using namespace std;
int main(){ int num;
bool flag = false;
    cout<<"This Program will find if the given number is power of 2 or not.\n Input the NUMBER : ";
    cin>> num;
   int num2=num;
   int num3=num;
//Method 1----
    while(num){
        if((num%2==0) && (num>=2)){
            num/=2;
        }else if((num==1) || (num ==0))
        {
            cout<<"Method 1 states : YES, a power of 2\n";
            break;
        }   
        else{
            cout<<"Method 1 states : NOT a power of 2\n";
            break;
        }} 
        if (num==0)
        {
            cout<<"Method 1 states : YES, a power of 2\n";
        }
// Method 2-----
        
      {  while((num2%2==0) && (num2>=2)){
            num2/=2;
        }if (num2==1 || num2 == 0)
        {
            cout<<"Method 2 states : YES, a power of 2\n";
        }else{
            cout<<"Method 2 states : NOT a power of 2\n";
        
    }}
// Method 3----
int num4;
num4 = num3;
//cout<<num3<<num4;
    while((num3==(num4>>1)<<1)){
        num3/=2;
        num4/=2;
        if (num3==0)
        {
            break;
        }
        
    }num3/=2;
    num4/=2;
    while((num3==(num4>>1)<<1)){
        num3/=2;
        num4/=2;
        if (num3==0)
        {
            cout<<"Method 3 states : YES, a power of 2\n";
            flag = true;
            break;
        }}
        if(flag==false)
        {
           cout<<"Method 3 states : NOT a power of 2\n";
        }
    return 0;
}

