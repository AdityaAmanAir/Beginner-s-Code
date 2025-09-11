#include<bits/stdc++.h>

using namespace std;
int main(){
int t,initial_balance;
string line;
vector<string> s;
cin>>initial_balance>>t;
for(int i=0;i<t;i++){
    cin>>line;
    s.push_back(line);
}
 int balance = initial_balance;
    vector<pair<int, int>> transactions; 
    vector<int> commits;
    int transaction_count = 0;
    int commit_count = 0;

    for (const string& op_line : s) {
        istringstream iss(op_line);
        string op;
        iss >> op;
        
        if (op == "read") {
            cout << balance << endl;
        } else if (op == "credit") {
            int amount;
            iss >> amount;
            balance += amount;
            transaction_count++;
            transactions.push_back({amount, transaction_count});
        } else if (op == "debit") {
            int amount;
            iss >> amount;
            balance -= amount;
            transaction_count++;
            transactions.push_back({-amount, transaction_count});
        } else if (op == "abort") {
            int x;
            iss >> x;
            bool found = false;
            for (auto it = transactions.begin(); it != transactions.end(); ++it) {
                if (it->second == x) {
                    balance -= it->first; 
                    transactions.erase(it);
                    found = true;
                    break;
                }
            }
        } else if (op == "rollback") {
            int x;
            iss >> x;
            if (x <= commit_count) {
                balance = commits[x-1];
                transactions.clear();
            }
        } else if (op == "commit") {
            commits.push_back(balance);
            commit_count++;
            transactions.clear(); 
        }
    }

    return 0;
}