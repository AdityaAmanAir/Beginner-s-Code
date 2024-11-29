#include <iostream>
using namespace std;
int dig(int n){
    int digsum=0, ldigsum, m=1;
    while (n>0)
    {ldigsum=n%10;
    n/=10;
    digsum+=ldigsum;
    }
    return digsum;
}
int main()
{int Z;
    cout << "This programm will count he sum of the digits of the given number. \n Enter the number : ";
    cin >> Z;
    cout  <<  "The sum of the digist are "<< dig(Z)<< endl;

    cout  <<  "The sum of the digist 1234 are "<< dig(1234)<< endl;
    cout  <<  "The sum of the digist 10045 are "<< dig(10045)<< endl;
    cout  <<  "The sum of the digist 003407 are "<< dig(003407)<< endl;
    cout  <<  "The sum of the digist -0100005 are "<< dig(-0100005)<< endl; 
return 0;
}
