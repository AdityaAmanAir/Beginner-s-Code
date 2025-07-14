#include <iostream>
using namespace std;

int main() {
   int arr[]={10,20,30,40,50};
int*p = arr;
cout<< *(p+3)<<endl;
cout<< *(p+1)<<endl;
cout<< *(p)<<endl;
return 0;
}