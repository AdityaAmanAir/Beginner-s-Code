#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    string aadhaar;
    cout << "Enter Aadhaar number: ";
    cin >> aadhaar;

    pid_t pid = fork();

    if (pid == 0) { // Child
        int sum = 0, count = 0;
        for (char c : aadhaar) {
            int d = c - '0';
            if (d % 2 == 0) {
                sum += d;
                count++;
            }
        }
        if (count > 0)
            cout << "Child: Average of even digits = " << (float)sum/count << endl;
        else
            cout << "Child: No even digits found.\n";
    } else { // Parent
        wait(NULL);
        int sum = 0, count = 0;
        for (char c : aadhaar) {
            int d = c - '0';
            if (d % 2 != 0) {
                sum += d;
                count++;
            }
        }
        if (count > 0)
            cout << "Parent: Average of odd digits = " << (float)sum/count << endl;
        else
            cout << "Parent: No odd digits found.\n";
    }
    return 0;
}