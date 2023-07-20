#include <deque>
#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    deque<pair<int, int> > myDeque;

    int N, L;
    int num;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> num;
        pair<int, int> node(i, num);
        while (myDeque.size() && myDeque.back().second >= num) {
            myDeque.pop_back();
        }
        myDeque.push_back(node);
        if (myDeque.front().first < i - L + 1) {
            myDeque.pop_front();
        }
        cout << myDeque.front().second << ' ';
    }

    return 0;
}