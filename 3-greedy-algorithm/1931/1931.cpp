#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int> > list(n);

    for (int i = 0; i < n; i++) {
        // 종료 시각 기준 정렬을 위해 first에 종료 시각 저장
        cin >> list[i].second;  // 시작 시각
        cin >> list[i].first;   // 종료 시각
    }

    sort(list.begin(), list.end());

    int count = 0;
    int endTime = 0;

    for (int i = 0; i < n; i++) {
        if (endTime <= list[i].second) {
            endTime = list[i].first;
            count++;
        }
    }

    cout << count;

    return 0;
}