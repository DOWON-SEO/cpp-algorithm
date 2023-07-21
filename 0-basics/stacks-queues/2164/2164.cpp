#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    queue<int> cards;

    for (int i = 1; i <= n; i++) {
        cards.push(i);
    }

    while (cards.size() > 1) {
        cards.pop();
        if (cards.size() == 1) break;
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();

    return 0;
}