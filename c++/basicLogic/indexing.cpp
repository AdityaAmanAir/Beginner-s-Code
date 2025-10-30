#include<iostream>
using namespace std;
int main(){
    
    int arrayempty[0]={};
    cout<<arrayempty<<" "<<arrayempty[0]<<endl;

    int myarray[10]={0,1,2,3,4,5,6,7,8,9};
    int myarray2[10]={0,-1,-2,-3,-4,-5,-6,-7,-8,-9};

    cout<<myarray<<endl;
    cout<<myarray2<<endl;
    for(int i=0; i<=25;i++){  cout<<myarray[i]<<endl;}

    cout<<"----------------------------\n";

    for(int i=0; i<=25;i++){  cout<<myarray[-i]<<endl;}

    cout<<"----------------------------\n";

    char myarrayc[10]="mmQdAKxXi";
    char myarray2c[10]="ABCdEfGHi";

    cout<<myarrayc<<endl;
    cout<<myarray2c<<endl;
    for(int i=0; i<=25;i++){  cout<<myarrayc[i]<<endl;}

    cout<<"----------------------------\n";

    for(int i=0; i<=25;i++){  cout<<myarrayc[-i]<<endl;}


    cout<<"///////////////////////////////////////\n";

    char myarraya[10]={'m','m','Q','d','A','K','x','X','i'};
    char myarray2a[10]={'a','b','c','D','e','F','g','h','I'};

    cout<<myarraya<<endl;
    cout<<myarray2a<<endl;
    for(int i=0; i<=25;i++){  cout<<myarraya[i]<<endl;}

    cout<<"----------------------------\n";

    for(int i=0; i<=25;i++){  cout<<myarraya[-i]<<endl;}


    return 0;
}