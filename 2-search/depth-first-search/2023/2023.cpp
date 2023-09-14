#include <iostream>
using namespace std;

static int length;

bool isPrimeNumber(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void DFS(int num, int numCount) {
    if (numCount == length && isPrimeNumber(num)) {
        cout << num << '\n';
    }
    if (isPrimeNumber(num)) {
        for (int i = 1; i < 10; i = i + 2) {
            DFS(num * 10 + i, numCount + 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> length;
    int numCount = 1;

    DFS(2, numCount);
    DFS(3, numCount);
    DFS(5, numCount);
    DFS(7, numCount);

    return 0;
}