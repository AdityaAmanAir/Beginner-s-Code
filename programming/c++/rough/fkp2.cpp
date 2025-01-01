#include <iostream>
#include <cmath>
using namespace std;
int allprime(int N){
    int count =0;
    for ( int i = 2; i <= N; i++)
    {
         for (int j = 1; j <= i; j++)
        {
        
            if(i%j==0){
            count = count + 1;
            }
            if (count==2)
            {
                cout << i;
            }else{
                continue;
            }
            
        }
    
    }

    

return 0;
}
int main()
{int num;
cout<<"Enter the number, till where you have to find all the prime number between them : ";
cin>>num;
cout<<allprime(num);
return 0;
}