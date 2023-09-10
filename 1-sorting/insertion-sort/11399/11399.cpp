#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 1; i < n; i++) {
        int temp = list[i];
        for (int j = 0; j < i; j++) {
            if (list[j] > list[i]) {
                for (int k = i - 1; k >= j; k--) {
                    list[k + 1] = list[k];
                }
                list[j] = temp;
            }
        }
    }

    int temp = 0;
    int output = 0;
    for (int i = 0; i < n; i++) {
        temp += list[i];
        output += temp;
    }

    cout << output;

    return 0;
}