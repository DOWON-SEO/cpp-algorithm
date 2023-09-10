#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, D;
    long long max = 0;
    cin >> N >> D;
    vector<pair<long long, long long> > gift(N);
    for (int i = 0; i < N; i++) {
        cin >> gift[i].first >> gift[i].second;
    }

    sort(gift.begin(), gift.end());  // 가격순 정렬

    int start = 0;
    int end = 0;
    int sumValue = 0;
    int output = 0;
    while (end < N) {
        int priceGap = gift[end].first - gift[start].first;
        if (priceGap == D) {
            max = max < output ? output : max;
        } else if (priceGap > D) {
            output -= gift[start].second;
            start++;
        } else if (priceGap < D) {
            output += gift[end].second;
            end++;
        }
        cout << output;
    }

    cout << max;

    return 0;
}