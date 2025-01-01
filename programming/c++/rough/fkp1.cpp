#include <iostream>
using namespace std;
int main()
{
string Name, colour;

    cout << "This Programm will tell about yourself\n Tell me your name : ";
    cin >>Name;
    cout<< "That is your colour ? (B/W) ";
    cin >> colour;
if (Name== "Rohan" && colour == "B")
{
    cout << Name << " is a GOOD boy!";

}
if (Name== "Aditya" && colour == "W")
{
    cout << Name << " is a BAD boy!";
}
else{
    cout << " User data not found";
}


    return 0;
}