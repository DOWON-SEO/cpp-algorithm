#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int N, P;
    cin >> N >> P;
    string str;
    cin >> str;

    int A, C, G, T;
    cin >> A >> C >> G >> T;
    int output = 0;
    int aCount = 0;
    int cCount = 0;
    int gCount = 0;
    int tCount = 0;
    for (int i = 0; i < P; i++) {
        if (str[i] == 'A') aCount++;
        if (str[i] == 'C') cCount++;
        if (str[i] == 'G') gCount++;
        if (str[i] == 'T') tCount++;
    }
    for (int i = P; i <= N; i++) {
        if (A <= aCount && C <= cCount && G <= gCount && T <= tCount) output++;
        if (i == N) break;
        if (str[i - P] == 'A') aCount--;  // 0부터 (마지막-P)까지
        if (str[i - P] == 'C') cCount--;
        if (str[i - P] == 'G') gCount--;
        if (str[i - P] == 'T') tCount--;
        if (str[i] == 'A') aCount++;  // P부터 마지막까지
        if (str[i] == 'C') cCount++;
        if (str[i] == 'G') gCount++;
        if (str[i] == 'T') tCount++;
        // cout << aCount << cCount << gCount << tCount << '\n';
    }
    // cout << aCount << '\n';
    // cout << cCount << '\n';
    // cout << gCount << '\n';
    // cout << tCount << '\n';
    cout << output;

    return 0;
}