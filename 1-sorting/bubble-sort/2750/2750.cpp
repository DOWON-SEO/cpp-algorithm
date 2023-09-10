#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << list[i] << '\n';
    }

    return 0;
}