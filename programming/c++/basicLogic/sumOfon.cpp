#include <iostream>
using namespace std;
int main()
{int64_t Number; int64_t sum = 0; int64_t i = 1;
    cout << "\n This programme will tell you the sum of odd n natural number\n  Enter the Number : ";
    cin>> Number;
    if(Number%2== 1)
    {
        { while(i<= Number)
        {
         sum = sum + i;
         i += 2 ;
        }
        }
        {
            cout << " The sum of " << Number<< " odd number is : " << sum <<"\n";
        }
    }
    else
    {
        cout << " The Number is not odd number!\n";
    }
 return 0;
}