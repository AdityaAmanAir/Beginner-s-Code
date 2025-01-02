#include <iostream>
using namespace std;
int main ()
{   int64_t side; int64_t number =1;
    cout << " This programm will make a right angele isosceles triangle using number is patten. \n Enter the side length of the tringle : ";
    cin >> side;
    for(int i = 0; i<side; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << number++;
        }
        cout << "\n";
        number =1;
    }
    return 0;
}