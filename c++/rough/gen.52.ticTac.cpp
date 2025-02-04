#include <iostream>
#include <vector>
using namespace std;

bool checkWin(const vector<string> &grid, char first) {
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == first || grid[i][0] == ' ') && grid[i][1] == first && grid[i][2] == first) return true;
        if ((grid[0][i] == first || grid[0][i] == ' ') && grid[1][i] == first && grid[2][i] == first) return true;
    }
    if ((grid[0][0] == first || grid[0][0] == ' ') && grid[1][1] == first && grid[2][2] == first) return true;
    if ((grid[0][2] == first || grid[0][2] == ' ') && grid[1][1] == first && grid[2][0] == first) return true;
    return false;
}

int main() {
    string first;
    vector<string> grid(3);
    getline(cin, first);
    for (int i = 0; i < 3; i++) getline(cin, grid[i]);

    cout << (checkWin(grid, first[0]) ? "Yes you can." : "No you can't.");
    return 0;
}
// lol wrong answers.... xD not working code 