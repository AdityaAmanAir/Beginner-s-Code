#include <iostream>
using namespace std;

int sumN(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum+=i;
    }
    return sum;
    }

int main()
{
    int Z;
    cout << "This program will count the sum of n natural number using function. \n Enter the number ";
    cin >> Z;
    cout << "The sum of the Z natural number is " << sumN(Z) <<endl;
    
    cout << "The sum of the 1 number is " << sumN(1)<< endl;
    cout << "The sum of the 2 number is " << sumN(2)<< endl;
    cout << "The sum of the 3 number is " << sumN(3)<< endl;
    cout << "The sum of the 4 number is " << sumN(4)<< endl;
    cout << "The sum of the 5 number is " << sumN(5)<< endl;

    
  return 0;
}