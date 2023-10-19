#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> list(n);

    int result = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        int coinValue = list[i];
        while (k - result >= coinValue) {
            result += coinValue;
            count++;
        }
    }

    cout << count;

    return 0;
}