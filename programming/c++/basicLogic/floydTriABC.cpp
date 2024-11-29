#include <iostream>
using namespace std;
int main ()
{   int64_t side; char A ='A';
    cout << " This programm will form floyd Triangle using alphabets \n Enter the side of triangle : ";
    cin >> side;
    for (int i = 0 ; i<side; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (A>'Z')
            {
                A = 'A';
            }
            cout << A++;
        } cout << "\n";
    }

    return 0;
}