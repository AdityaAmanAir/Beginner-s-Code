#include<iostream>
#include<string>
using namespace std;

/*int mod(int x,int n, int y){
    int pro=1;
    if(n>1){
        n--;
        if (n%2!=0){
        return ((mod(x, n, y))%y);
        }else{
            return (x*(mod(x, n, y)));
        }
    }else{
        return (x%y)*(x%y);
    }
}
*/
int mod(int x, int n, int y) {
    if (n == 0)
        return 1;  // base case: x^0 = 1

    long long half = mod(x, n / 2, y);  // recursively compute x^(n/2)
    long long result = (half * half) % y;

    if (n % 2 == 1)  // if n is odd, multiply by x one more time
        result = (result * (x % y)) % y;

    return result;
    
}
/*
int exp(int base, int exponent) {
    long long result = 1;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}
*/
int main(){
    string user1, user2;
    long long encryption[100];
    char charEncry[100];
    cout<<"Enter your message : ";
    getline(cin, user1);
    for (int j=0; j<=100;j++){
        encryption[j]=0;
        charEncry[j]=0;
    }
    int i=0;
    for(char c : user1){
        encryption[i]=int(c);
        i++;
    }
  /*  for (int j=0; j<100;j++){
        cout<<encryption[j]<<" ";
    }
        */

cout<<"\n-------------------\n";
    int A,B;
    A=5, B=221;
    for (int j=0; j<user1.length();j++){
        // inscription[j]=(exp(inscription[j],A)%B);
        // if (inscription[j]<0){
        //     inscription[j]=inscription[j];
        // }
        encryption[j]= mod(encryption[j],A,B);
        charEncry[j]=char(encryption[j]);
    }

   /* for (int j=0; j<100;j++){
        cout<<encryption[j]<<" ";
    }
        */
     for (int j=0; j<100;j++){
         cout<<char(encryption[j])<<" ";
     }
    return 0;
}