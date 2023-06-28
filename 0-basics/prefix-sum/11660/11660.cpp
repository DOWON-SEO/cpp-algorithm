#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int size, count;
    cin >> size >> count;

    vector<vector<int> > table(size + 1, vector<int>(size + 1, 0));
    vector<vector<int> > sums(size + 1, vector<int>(size + 1, 0));

    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            cin >> table[i][j];
            sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + table[i][j];
        }
    }

    for (int i = 0; i < count; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = sums[x2][y2] - sums[x2][y1 - 1] - sums[x1 - 1][y2] + sums[x1 - 1][y1 - 1];
        cout << result << '\n';  // endl은 버퍼를 지우는 작업도 같이 하여 오버헤드가 크다
    }
    return 0;
}