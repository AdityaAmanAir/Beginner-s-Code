#include <iostream>
using namespace std;
int main ()
{ 
    cout << " This programm will print A B C D  for 4 iteration \n";
    for (int i=0; i<4 ; i++)
    {
        char alphabet = 'A';
        for (int i = 0; i < 4 ; i++ )
        {
            cout << alphabet++;
        }
        cout << "\n";
    }
 
    return 0;
}