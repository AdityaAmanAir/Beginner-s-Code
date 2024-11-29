#include <iostream>
using namespace std;
int main()
{
    int64_t side;int line =1;
    cout << " This programm will make an isosceles  right angle triangle using stars * \n. Enter the side of an Triangle : ";
    cin >> side;
    for (size_t j = 0; j < side; j++)
    { 
       for (size_t i = 0; i < j+1; i++) // insted of j +1 , line can be use , code is already implemented 
        {
            cout << "*";
        }
        line++;
        cout << "\n";
    }
    return 0;
}