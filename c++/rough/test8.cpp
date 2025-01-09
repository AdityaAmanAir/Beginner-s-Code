#include <iostream>
using namespace std;

int main() {
	int x=0,p=0,a;
	cin>>a;
	while (x<=a){
	    x++;
	    if(x==10){
	        p+=1;
	        x=0;
	    }
	} cout<<p;
}