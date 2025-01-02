#include <iostream>
using namespace std;
int main()
{int64_t height;char A ='A';
    cout<<" This programm will for an inverted isosceles right triangle using Alphabets.\n Enter the height of the tringle : ";
    cin>> height; 
    for (int i=0; i<height; i++)
    {
        for (int j =0; j<=i; j++)
        {
            cout << " ";
        }
        for (int k=height-i;k>0;k--)
        {
            cout << A;
        }cout<< "\n";
        A++;
        if(A>'Z')
        A='A';
    }
    return 0;
}