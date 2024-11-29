#include <iostream>
using namespace std;
int main()
{
    char Alphabet;
    cout << " \n This programme will tell you that if the character is in upper case or lower case.\n \n Enter the Alphabet : ";
    cin >> Alphabet;
    if (65<= Alphabet && Alphabet <= 90)
    {
        cout << "The Aplphabet "<< Alphabet << " is in Upper case.\n";
    }
    else if (97<= Alphabet && Alphabet <= 122)
    {
        cout << "The Aplphabet "<< Alphabet << " is in lower case.\n";
    }
    else
    {
        cout << " The character is not an Alphabet!";
    }
    return 0;
}