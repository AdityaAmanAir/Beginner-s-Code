#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n;
    double sum=0;
    cin>>n;
   for (int i = n; i > 0; i--)
   {
    double x,y;
    cin>>x>>y;
    sum+=((y-x)*(y-x));
   }
   cout<<setprecision(17)<<sqrt(sum);
    return 0;
}

