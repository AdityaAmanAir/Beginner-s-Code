#include <iostream>
using namespace std;
int main()
{ int64_t Number;
    cout << " \n This Programme will tell you that if a number is odd or Even.\n \n Insert a number : ";
    cin >> Number;
   
        if (Number%2==0)
        {
            cout << "The number " << Number << " is EVEN.\n";
        }else {
            cout << "The number " << Number << " is ODD.\n";
        }
    return 0;
}