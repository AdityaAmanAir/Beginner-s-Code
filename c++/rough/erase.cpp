#include <iostream>
#include <vector>

using namespace std;

// Function to count valid sequences
int count_valid_sequences(vector<int>& A, int k) {
    int n = A.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += A[j]; 
            if (current_sum >= k) {
                count++;
                break; // Stop early if sum >= k
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Extend list `a` by repeating `k` times
        vector<int> b;
        for (int i = 0; i < k; i++) {
            b.insert(b.end(), a.begin(), a.end());
        }

        // Print the count of valid sequences
        cout << count_valid_sequences(b, x) << endl;
    }

    return 0;
}
