#include <iostream>
using namespace std;
int main ()
{int64_t side;
    cout << " This programm will form a floyd alphabatic triangle in reverse \n Enter the length of the side : ";
    cin >> side;
    for (int i =0; i<side; i++)
    {
        for (char A =('A'+i); A>='A'; A--)
        {
            cout << A;
        }
        cout << "\n";
    }
    return 0;
}