#include <iostream>
#include <cmath>

int sqt(int n) {
    int x = 1;
    while (x < n) {
        if (x * x >= n) {
            x--;
            break;
        }
        x++;
    }
    return x;
}

int main() {
    int num = 0x311F5;  // 200789 in decimal (hexadecimal to match the assembly initialization)
    int sq_root = sqt(num);  // Call sqt function to compute square root approximation
    int sum = 0;
    for (int i = 1; i <= sq_root; ++i) {
        if (num % i == 0) {
            if (i * i == num) {
                sum += i;  // Perfect square case
            } else {
                sum += i + num / i;  // Add both divisors
            }
        }
    }
    std::cout << "Sum of divisors: " << sum << std::endl;
    return 0;
}
