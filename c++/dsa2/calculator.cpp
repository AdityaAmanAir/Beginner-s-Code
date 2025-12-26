#include<iostream>
using namespace std;
int main(){
    float a,b;
    char o;
    cin>>a>>o>>b;
    switch (o)
    {
    case '+':
        cout<<a+b;
        break;
    
    case '-':
        cout<<a-b;
        break;
    
    case '*':
        cout<<a*b;
        break;
    case '/':
        cout<<a/b;
        break;        
    default:
        cout<<"INVALID\n";
        break;
    }

    return 0;
}