#include<iostream>
using namespace std;
int main()
{int number; int start =1;
    cout << " This Program will make square patten using numbers from 1. \n Enter the dimention of square : ";
    cin>> number;
        for(int i=0; i<number; i++)
    {
        for( int i=0 ;i <number; i++ )
        {
            cout << start;
            start++;
            
        } cout<<"\n";
    }
    return 0;
}