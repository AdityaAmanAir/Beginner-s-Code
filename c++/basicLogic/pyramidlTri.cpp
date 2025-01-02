#include <iostream>
using namespace std;
int main()
{int64_t number;
    cout<<" This programm will for Pyramid Triangle. \n Enter the number upto which you need the Bionomial Triangle : ";
    cin >> number;
    for ( int i =0; i<number;i++)
    {
        for(int j= number-i;j>0;j--)
        {
            cout << " ";
        }
        for(int k=0;k<=i;k++)
        {
            cout << (k+1);
        }
        for (int l=i;l>=1;l--)
        {
            cout << l;
        }
        cout << "\n";
    }

    return 0;
}