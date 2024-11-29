#include <iostream>
using namespace std;
int main ()
{int64_t side; 
    cout << " This programm will form a mirror right isosceles triangle using repeated numbers. \n Enter the length of the side : ";
    cin >> side;
    for(int i=0; i<side; i++)
    {int64_t number =1;
        for(int j=0; j<(side -i);j++)
        {
            cout << number++;
        }
        cout << "\n";
    }
    return 0;
}