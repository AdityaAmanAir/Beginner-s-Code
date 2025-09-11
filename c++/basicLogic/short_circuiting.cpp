#include<iostream>
using namespace std;
int main(){

    int x,y=21;
    cin>>x;

    cout<<((x>0)&&(y/x));//this will NOT give Floating point exception, because the short circuit operation (they are evaluated from left to right). In short circuit, if ->(false && "any" && "any" && "any" ...) here it will break out in the first step as soon as it found False. If ->(true || "any" || "any" || "any" ...) here it will break out in the first operation, as soon as  it get false.

    cout<<((y/x)&&(x>0));//this will give Floating point exception 
    return 0;
}