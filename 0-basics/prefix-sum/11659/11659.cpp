#include <iostream>
#include <vector>
using namespace std;

int main() {
    int length, count, i, a, b;
    vector<int> numbers(length);
    vector<int> sums(length);
    cin >> length >> count;
    for (i = 0; i < length; i++) {
        cin >> numbers[i];
    }

    sums[0] = numbers[0];

    for (i = 1; i < length; i++) {
        sums[i] = sums[i - 1] + numbers[i];
    }

    for (i = 0; i < count; i++) {
        cin >> a >> b;
        cout << sums[b - 1] - sums[a - 2] << endl;
    }
}