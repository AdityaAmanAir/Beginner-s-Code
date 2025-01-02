#include <iostream>
using namespace std;
int main()
{int dimention; char startingChar='A', Z='Z';
    cout<< " This programm will form the patten, starting from the alphabet A. \n Enter the dimention of square : ";
    cin >> dimention;
    for(int j=0; j<dimention; j++)
    {
        for(int i=0; i<dimention; i++)
        {
            cout<<startingChar++<<" ";
            if (startingChar>'Z')
            {
             startingChar='A';
            }
            
            
        }cout << "\n";
    }
    return 0;
}