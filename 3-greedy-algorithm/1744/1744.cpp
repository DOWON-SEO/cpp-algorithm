#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> list(n);

    priority_queue<int> positive;
    priority_queue<int, vector<int>, greater<int> > negative;

    int result = 0;
    int zeros = 0;
    int ones = 0;

    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        if (temp > 1) {
            positive.push(temp);
        } else if (temp < 0) {
            negative.push(temp);
        } else if (temp == 1) {
            ones++;
        } else if (temp == 0) {
            zeros++;
        }
    }

    sort(list.begin(), list.end(), greater<int>());

    int a, b;

    while (positive.size() > 1) {
        a = positive.top();
        positive.pop();
        b = positive.top();
        positive.pop();
        result += a * b;
    }

    if (!positive.empty()) result += positive.top();

    while (negative.size() > 1) {
        a = negative.top();
        negative.pop();
        b = negative.top();
        negative.pop();
        result += a * b;
    }

    if (!negative.empty() && zeros == 0) result += negative.top();

    result += ones;

    cout << result;

    return 0;
}