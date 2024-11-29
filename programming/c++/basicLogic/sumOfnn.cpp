#include <iostream>
using namespace std;
int main()
{ int64_t sum = 0; int64_t Number; int64_t sum2;
    cout << "\n This programme will tell you the sum of N natural number from 1 to N\n Enter a Number : " ;
    cin >> Number;
    
        for(int i = 0; i <= Number; i++)
    {
        sum += i; // sum = sum +i
    }
    sum2 = (Number*(Number+1))/2 ;
    if (sum==sum2)
    {
        cout << " The sum of first " << Number << " numbers are : " << sum <<"\n";
    }else{
        cout << " Given Input is not valid !";
    }
return 0;
}