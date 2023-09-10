#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int count = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i + 1]) count++;
    }
    cout << count;

    // bool changed = false;
    // for (int i = 1; i <= N + 1; i++) {
    //     changed = false;
    //     for (int j = 1; j <= N - i; j++) {
    //         if (A[j] > A[j + 1]) {
    //             changed = true;
    //             int temp = A[j];
    //             A[j] = A[j + 1];
    //             A[j + 1] = temp;
    //         }
    //     }
    //     if (changed == false) {
    //         cout << i << '\n';
    //         break;
    //     }
    // }

    return 0;
}