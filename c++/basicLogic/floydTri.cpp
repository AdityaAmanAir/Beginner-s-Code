#include <iostream>
using namespace std;
int main()
{int64_t side;int number = 1;
    cout << " This program will form Floyd's Tringle \n Enter the number :  ";
    cin >> side;
    for (int i=0; i<side; i++)
    {
        for(int j= 0; j<i; j++)
        {
            cout << number++;
        }
        cout << "\n";

    }
 return 0;
}