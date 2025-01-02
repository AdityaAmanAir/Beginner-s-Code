#include <iostream>
using namespace std;
int main()
{int64_t side;int number =0;
    cout << " This programm will form a mirror right isosceles triangle using repeated numbers. \n Enter the length of the side : ";
    cin >> side;
    for(int i=0; i<side;i++)
    {
        number++;
        for (int j=side-i; j>0; j--)
        {
            cout << number;
        } cout<<"\n";

    }
    return 0;
}