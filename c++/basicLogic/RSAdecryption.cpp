#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int phi(int n) {
    int result= n;
    for (int p= 2; p*p <= n; ++p) {
        if (n % p ==0) {
            while (n % p == 0)
                n /= p;
            result-=result / p;
        }
    }
    if (n > 1)
        result-=result / n;
    return result;
}

int modInverse(int e, int phi_n) {
    int t= 0, newt= 1;
    int r = phi_n, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt =t - quotient*newt;
        t = temp;
        temp = newr;
        newr = r -quotient * newr;
        r =temp;
    }
    if (r > 1) return -1; // not invertible
    if (t < 0) t += phi_n;
    return t;
}

int mod(int x, int n, int y) {
    if (n == 0)
        return 1;
    long long half = mod(x, n/2, y);
    long long result = (half* half)%y;
    if (n % 2 == 1)
        result = (result *(x%y))%y;
    return result;
}

int main() {
    int p, q;
    cout <<"Enter two prime numbers: ";
    cin>>p>>q;

    int n = p*q;
    int phi_n = (p-1)*(q-1);

    int e;
    for (e = 2; e < phi_n; e++) {
        if (gcd(e, phi_n) == 1)
            break;
    }

    int d=modInverse(e, phi_n);
    if (d == -1) {
        cout << "No modular inverse exists for chosen e." << endl;
        return 1;
    }

    cout <<"Public Key (e, n): (" <<e<< ", " << n << ")"<<endl;
    cout <<"Private Key (d, n): (" <<d<< ", " << n << ")"<<endl;

    string message;
    cout << "Enter message to encrypt: ";
    cin.ignore();
    getline(cin, message);

    cout << "Encrypted ASCII values: ";
    for (char ch : message) {
        int enc = mod(int(ch), e, n);
        cout << enc << " ";
    }
    cout<<endl;

    return 0;
}
