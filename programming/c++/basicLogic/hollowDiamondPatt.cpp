#include <iostream>
using namespace std;
int  main ()
{int side; 
    cout << " This programm will form a hollow Diamond patten using * . \n  Enter the side length : ";
    cin>> side ; int numb = (2*side);
    for(int i=0; i<side; i++)
    {
        for (int j=0; j<side-i-1;j++)
        {
            cout << " ";
        }
            cout << "*";
        
        for (int l=1; l<=i;l++)
        { 
            cout << " ";
        }
        for (int m=2; m<=i;m++)
        {
            cout << " ";
        }
        if(i!=0)
        {
            for (int n=0;n<1;n++)
        {
        cout<<"*"; 
        }
        }
        cout<<"\n";
    }
    for(int i=0;i<side;i++)
    {
        for(int m=0; m<=i; m++)
        {
            cout << " ";
        }
        if (i!=side-1)
        {
            cout << "*";
        }
        for(int n=side-i; n>2; n--)
        {
            cout << " ";
        }
        for (int j=side-i-2;j>1;j-- )
        {
            cout << " ";
        }
        if (i<side-2)
        {
            cout << "*";
        }
        cout<<"\n";
    }
    return 0;
}