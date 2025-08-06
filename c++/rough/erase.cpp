#include <iostream>
using namespace std;
int main() {
   long long int t,a,b;
   cin>>t>>b>>a;

   cout<<((t/a)*(b/a))+((b%a==0)?0:(t/a))+((t%a==0)?0:(b/a))+(((b%a!=0)&&(t%a!=0))?1:0);
return 0;
}