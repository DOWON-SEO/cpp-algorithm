#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> list(n);
    vector<int> outputList(n, -1);
    stack<int> myStack;

    int num;
    int index = 0;

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        while (myStack.size() != 0 && list[i] > list[myStack.top()]) {
            outputList[myStack.top()] = list[i];
            myStack.pop();
        }
        myStack.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << outputList[i] << ' ';
    }

    return 0;
}