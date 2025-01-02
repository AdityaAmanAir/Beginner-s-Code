#include <iostream>
using namespace std;
int factor(int f){
    int ans;
for (int i = 1; i <= f; i++)
{
    ans= i*ans;
}

    return ans;
}
int main(){
    int Z;
    cout <<"This programm will find the factorial of the functions using functions.\n Enter the natural number : ";
    cin>> Z;
    cout<< "The factorial of " <<Z << "is "<< factor(Z) << endl;

    cout<< "The factorial of " <<2 << "is "<< factor(2) << endl;
    cout<< "The factorial of " <<3 << "is " <<factor(3) << endl;
    cout<< "The factorial of " <<4 << "is " <<factor(4) << endl;
    cout<< "The factorial of " <<5<< "is " <<factor(5) << endl;




    return 0;
}