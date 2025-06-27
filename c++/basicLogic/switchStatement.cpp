#include <iostream>
using namespace std;
int main(){

    int a ,b;
    cin>>a>>b;
    switch (a && b)
    {
    case (2 && 3):
        cout<<"2 3";
        break;
    case (12 , 13):
        cout<<"12 13";
        break;
    case (2, 4):
        cout<<"2 4";
        break;
    case (2,6):
        cout<<"3 2";
        break;
    case (4 , 12):
        cout<<"4 12";
        break;
    default:
        break;
    }



    return 0;
}