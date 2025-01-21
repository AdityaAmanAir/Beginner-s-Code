/*
Given, resistance r =10 
Voltage in the form of data from 0 to 20
we have to store the I (current) in the array
V=IR
I=V/R
*/

#include <iostream>
using namespace std;
int main(){
    double r=10, v[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
    double I[sizeof(v)/sizeof(v[0])];
     int i=0;
     int j= (sizeof(v)/sizeof(v[0]));
     int k=j;
    while(j--){
        I[i]=v[i]/r;
    i++;
    }
    cout<<"Value of r = 10 \nValues of V :";

for ( i = 0; i < k; i++) 
    {
        cout<<v[i]<<", ";
    }
    cout<<"\nValues of I :";
    for ( i = 0; i < k; i++) // The vales of I has been stored and to show it on the terminal I have to use the loop to give the output of all the element stored in Array I[]
    {
        cout<<I[i]<<", ";
    }
    
    return 0;
}