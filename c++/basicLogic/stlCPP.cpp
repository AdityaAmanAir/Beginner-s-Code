//NAME : ADITYA AMAN
//REG. NO : 24BAI10129

#include<iostream>
#include<vector>
#include<list>
#include<stack>                                                                            
#include<algorithm>

using namespace std;

void fun_stack() {
    stack<int> stack1;
    cout << "Initial stack size: " << stack1.size() << endl;

    stack1.push(10);
    stack1.push(12);
    stack1.push(9);
    cout << "Pushed 10, 12, 9 into the stack.\n";

    stack1.pop();
    cout << "Popped top element. Current top: " << stack1.top() << endl;
}

void fun_vector() {
    vector<int> vec = {10, 20, 30, 40, 50};
cout << "Vector elements using begin() and end(): ";
for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
}
cout << endl;


    cout << "Vector max_size(): " << vec.max_size() << endl;
    cout << "Vector capacity(): " << vec.capacity() << endl;

    reverse(vec.begin(), vec.end());
    cout << "Reversed vector: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    cout << "Is vector empty? " << (vec.empty() ? "Yes" : "No") << endl;
    cout << "Element at index 2: " << vec.at(2) << endl;
    cout << "Front of vector: " << vec.front() << endl;
    cout << "Back of vector: " << vec.back() << endl;

    vec.erase(vec.begin() + 1);
    cout << "Vector after erase at index 1: ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    vec.clear();
    cout << "Vector after clear(), size: " << vec.size() << endl;

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    v1.swap(v2);
    cout << "After swap, v1: ";
    for (int val : v1) cout << val << " ";
    cout << endl << endl;
}

void fun_list() {
    list<int> l1 = {1, 3, 5};
    list<int> l2 = {2, 4, 6};
    l1.merge(l2);
    cout << "Merged list: ";
    for (int val : l1) cout << val << " ";
    cout << endl;
}

int main() {
    fun_stack;
    fun_vector();
    fun_list();
    return 0;
}
