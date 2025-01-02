#include <iostream>
using namespace std;
int main()
{int64_t Number;
    cout << " This program will print n number of *'s , in form n x n . \n Enter the number : ";
    cin >> Number;
    for (int64_t i = 0; i <= Number-1; ++i)
    { cout << "\n";
    for (int64_t i = 1; i <= Number; i++)
    {
       cout <<  "*";
    }}
    cout << endl;
    return 0;
    
}