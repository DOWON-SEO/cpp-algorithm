#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    long N, M;
    long count = 0;
    cin >> N >> M;

    vector<long> sums(N, 0);
    vector<long> remainList(M, 0);

    cin >> sums[0];
    for (int i = 1; i < N; i++) {
        int num;
        cin >> num;
        sums[i] = (sums[i - 1] + num);
    }

    for (int i = 0; i < N; i++) {
        int remainder = sums[i] % M;
        if (remainder == 0) count++;  // 나머지 0일 경우 count 수 증가
        remainList[remainder]++;      // 나머지가 0이 아닐 경우 나머지 증가
    }

    for (int i = 0; i < M; i++) {
        if (remainList[i] >= 2) {
            count += (remainList[i] * (remainList[i] - 1)) / 2;
        }
    }

    cout << count;

    return 0;
}