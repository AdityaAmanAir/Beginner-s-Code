#include <iostream>
using namespace std;
int main()
{   int side; char A= 'A';
    cout << " This programm will make a right angele isosceles triangle using alphabet is patten. \n Enter the side length of the tringle in : ";
    cin >> side;
    for (int i=0; i<side; i++)
    {
        for(int j= 0; j<=i; j++)
        {
            if(A>'Z')
            {
                A ='A';
                cout << A++;
            }else{
            cout << A++;
            }
        }
        cout << "\n";

    }
    return 0;
}