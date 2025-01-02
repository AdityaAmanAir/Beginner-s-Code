#include <iostream>
using namespace std;

int main() 
{
    double num1, num2;
    char op;

    cout << "\n This programme will help you to perform single operational task between two numbers.\n\n Enter the Operator ( + - * / %) : " ;
    cin >> op ;

    cout << "Enter the two one by one : ";
    cin >> num1 >> num2 ;


    switch (op)
    {
        case '+' :
        cout << num1 << op << num2 << " = " << (num1 + num2) << "\n" ;
        break;
    
        case '-' :
        cout << num1 << op << num2 << " = " << (num1 - num2) << "\n";
        break;

        case '/' :
        cout << num1 << op << num2 << " = " << (num1 / num2) << "\n";
        break;

        case '*' :
        cout << num1 << op << num2 << " = " << (num1 * num2) << "\n";
        break; 

        default:
        cout << "Invalid operaters ! ";
        break;
    }
 return 0;
}