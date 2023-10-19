#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> list(N);

    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int output = 0;
        int start = 0;
        int end = list.size() - 1;
        int middle = (start + end) / 2;
        int target;
        cin >> target;
        while (end >= start) {
            if (list[middle] == target) {
                output = 1;
                break;
            } else if (list[middle] < target) {
                start = middle + 1;
                middle = (start + end) / 2;
            } else {
                end = middle - 1;
                middle = (start + end) / 2;
            }
        }
        cout << output << "\n";
    }

    return 0;
}