#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(int a, int b) {
        int A = abs(a);
        int B = abs(b);
        if (A == B) return a > b;
        return A > B;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    priority_queue<int, vector<int>, compare> myQueue;

    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 0) {
            if (myQueue.size() == 0)
                cout << "0\n";
            else {
                cout << myQueue.top() << '\n';
                myQueue.pop();
            }
        } else {
            myQueue.push(num);
        }
    }

    return 0;
}