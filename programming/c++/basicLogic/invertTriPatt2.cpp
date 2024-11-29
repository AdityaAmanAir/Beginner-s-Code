#include <iostream>
using namespace std;
int main()
{   
    int64_t number; ;
    cout << " This programm will form a mirror right isosceles triangle using repeated numbers. \n Enter the length of the side : ";
    cin >>  number;
    for ( int i =0 ; i<number; i++)
        {
            for (int j=0; j<i;  j++)
            {
                cout<<" ";
            }
            for (int k=number-i; k>0; k--)
            {
                cout << (i+1);
            }
                        cout << "\n";
        }
    return 0;
}