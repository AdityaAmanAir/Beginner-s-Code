#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
// Data size of  FLOAT = 4 bites = 4*8 bits = 32 bits
float a=.1111111111111111111111;
std::cout << std::fixed << std::setprecision(20);
cout<<a<<endl;
float b= -1111111;
cout <<   b   <<endl; 
float c=2147483647  ;
cout <<   c   <<endl; 
float d = 2147483648 ;
cout <<     d <<endl; 
float  e= 1234567 ;
cout <<   e   <<endl; 

float f = 3.141592653589793;
    double g = 3.141592653589793;

    std::cout << "Float:  " << f << std::endl;
    std::cout << "Double: " << g << std::endl;

    return 0;
}