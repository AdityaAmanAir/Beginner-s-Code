#include <iostream>
using namespace std;
int main()
{   int64_t side;
    cout << " This programm will form a right isosceles triangle with number in reverse. \n Enter the side length of the tringle : ";
    cin >> side;
    for (int i=0; i<side; i++)
    {
        for(int j=i+1; j>0; j-- )
        {  
            cout<< j;
        }cout << "\n";
    }
    return 0;
}
