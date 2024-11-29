#include <iostream>
#include <cmath>
using namespace std;
int main()
{int64_t Number, i= 2;
bool isPrime = true;
    cout << "\n This program will tell you that if a number is Prime or not.\n Insert a number :  ";
    cin >> Number;
    int j=sqrt(Number);
    while (Number > 1 && i<= j)
    {
       if(Number%i==0)
            {
              isPrime = false;
              cout << " The number " << Number << " is NOT a Prime.";
             break;
            }
        else
            {
              ++i;
            }
    }
        if(isPrime == true && Number > 1)
        {
            cout << "The number " << Number << " is PRIME.";
        }
        else
        {
            cout << "The number " << Number << " is NOT a Prime.";
        }
     return 0;
}