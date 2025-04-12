#include<iostream>
#include<string>
using namespace std;
int mod(int x, int n, int y) {
    if (n == 0)
        return 1;  // base case: x^0 = 1

    long long half = mod(x, n / 2, y);  // recursively compute x^(n/2)
    long long result = (half * half) % y;

    if (n % 2 == 1)  // if n is odd, multiply by x one more time
        result = (result * (x % y)) % y;

    return result;
    
}

int main(){
    string user2;
    int decryption[100];
    char charEncry[100];
    for (int i=0; i<100;i++){
        cin>>charEncry[i];
    }
    for(int i=0; i<100; i++){
        decryption[i]=int(charEncry[i]);
    }
    
    for (int i=0; i<100;i++){
        cout<<decryption[i]<<" ";
    }
        
    int C,B;
    C=77,B=221;

    for (int j=0; j<100;j++){
        // inscription[j]=(exp(inscription[j],A)%B);
        // if (inscription[j]<0){
        //     inscription[j]=inscription[j];
        // }
        decryption[j]= mod(decryption[j],C,B);
        charEncry[j]=char(decryption[j]);
    }
    for (int i=0;i<100;i++){
        cout<<(decryption[i])<<" ";
    }    
    return 0;
}