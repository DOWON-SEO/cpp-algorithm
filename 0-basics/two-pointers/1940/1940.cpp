#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int count, sum;
    cin >> count >> sum;

    vector<int> serial(count, 0);

    for (int i = 0; i < count; i++) {
        cin >> serial[i];
    }
    int i = 0;
    int j = count - 1;
    int output = 0;
    sort(serial.begin(), serial.end());

    while (i < j) {
        if (serial[i] + serial[j] < sum) {
            i++;
        } else if (serial[i] + serial[j] == sum) {
            output++;
            i++;
            j--;
        } else if (serial[i] + serial[j] > sum) {
            j--;
        }
    }
    cout << output;
    return 0;
}