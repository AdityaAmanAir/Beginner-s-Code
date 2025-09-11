#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cmath>
#include <string>
#include <algorithm> // Add this line
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}
bool isAdditivePrime(int n) {
    int sum = 0, temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return isPrime(n) && isPrime(sum);
}
bool isCircularPrime(int n) {
    if (!isPrime(n)) return false;
    string s = to_string(n);
    for (size_t i = 0; i < s.size(); i++) {
        rotate(s.begin(), s.begin()+1, s.end());
        if (!isPrime(stoi(s))) return false;
    }return true;
}
int main() {
    int n;
    cout << "Enter number of primes in list: ";
    cin >> n;
    int arr[n];
    cout << "Enter prime numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    pid_t pid = fork();

    if (pid == 0) { // Child: Circular Primes
        cout << "Child: Circular Primes are: ";
        for (int i = 0; i < n; i++)
            if (isCircularPrime(arr[i])) cout << arr[i] << " ";
        cout << endl;
    } else { // Parent: Additive Primes
        wait(NULL);
        cout << "Parent: Additive Primes are: ";
        for (int i = 0; i < n; i++)
            if (isAdditivePrime(arr[i])) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}