#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int length;
    int count = 0;
    cin >> length;
    vector<int> A(length);

    for (int i = 0; i < length; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < length; i++) {
        int start = 0;
        int end = length - 1;
        while (start < end) {
            if (A[start] + A[end] == A[i]) {
                if (start == i) {
                    start++;
                } else if (end == i) {
                    end--;
                } else {
                    count++;
                    break;
                }
            } else if (A[start] + A[end] > A[i]) {
                end--;
            } else if (A[start] + A[end] < A[i]) {
                start++;
            }
        }
    }

    cout << count;

    return 0;
}