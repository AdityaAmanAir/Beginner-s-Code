#include <iostream>
#include <vector>
using namespace std;

int min_steps_to_sort_books(int n, vector<int>& p) {
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    int longest_seq = 1;
    int current_length = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] > pos[i - 1]) {
            current_length++;
        } else {
            current_length = 1;
        }
        longest_seq = max(longest_seq, current_length);
    }

    return n - longest_seq;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << min_steps_to_sort_books(n, p) << endl;
    return 0;
}
