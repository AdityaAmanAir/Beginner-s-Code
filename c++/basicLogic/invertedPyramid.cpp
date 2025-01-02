#include <iostream>
using namespace std;
int main()
{int64_t height;
    cout << " This programm will form a inverted Pyramid  \n Enter the height of the side : ";
    cin >> height;
    for (int i=0; i<height; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << " ";
        }
        for(int k=height-i; k>0;k--)
        {
            cout << (i+1)<<" ";
        }
        cout <<"\n";
    }
    return 0;
}