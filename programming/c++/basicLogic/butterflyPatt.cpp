#include <iostream>
using namespace std;
int main ()
{int wing;
    cout << " This programm will form a Butterfly Pattern.\n Enter the half length of the wings in integer : ";
    cin>> wing;
    for(int i=0; i<wing;i++)
    {
        for (int j=0; j<=i;j++)
        {
            cout << "*";
        }
        for (int k=wing-i-1; k>0;k--)
        {
            cout << " ";
        }
        for (int k=wing-i-1; k>0;k--)
        {
            cout << " ";
        }
        for (int j=0; j<=i;j++)
        {
            cout << "*";
        }
        cout<< "\n";
    }
    for (int i=0; i<wing;i++)
    {
        for (int k=wing-i; k>0;k--)
        {
            cout << "*";
        }
        for (int j=1;j<=i;j++)
        {
            cout << " ";
        }
        for (int j=1;j<=i;j++)
        {
            cout << " ";
        }
        for(int k=wing-i;k>0;k--)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}