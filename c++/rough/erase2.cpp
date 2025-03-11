#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,d=-1;
	    cin>>a;
	    while(a--){
	        cin>>b;
	        if(d<b) d=b;
	    }cout<<d<<endl;
	}
}