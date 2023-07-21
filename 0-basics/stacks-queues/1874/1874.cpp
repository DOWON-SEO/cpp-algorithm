#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n;
    int num;
    cin >> n;
    stack<int> myStack;
    string str = "";
    int index = 1;
    for (int i = 0; i < n; i++) {
        cin >> num;
        while (index <= num) {
            myStack.push(index++);
            str.push_back('+');
        }
        if (myStack.top() != num) {
            str = "";
            cout << "NO";
            break;
        } else {
            myStack.pop();
            str.push_back('-');
        }
    }
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << '\n';
    }

    return 0;
}