#include <iostream>
#include <cmath>
using namespace std;
void allprime(int N){
    for (int P = 3; P < N; P++)
    {bool T=true;
        for (int B = 2; B<=sqrt(P);B++)
        {
            if(P%B==0)
            {T=false;
            break;
            }
        }
        if(T==true){
        cout<<P<<" ";}       
    }
}
int main(){
    int num;
    cout<<"Enter the number, till where you have to find all the prime number between them : ";
    cin>>num;
    cout<< "2 ";
    allprime(num);
    return 0;
}