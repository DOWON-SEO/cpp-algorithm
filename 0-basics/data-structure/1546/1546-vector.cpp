// 백준 1546 (Bronze 1)

// 각 점수에 대해, (점수 / 최고점 * 100)의 평균값을 구하시오

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int length, i = 0;
    cin >> length;
    vector<double> scores(length);
    for (i = 0; i < length; i++) {
        cin >> scores[i];
    }

    for (i = 0; i < length; i++) {
        cout << scores[i] << endl;
    }

    double max = 0;
    double sum = 0;

    for (i = 0; i < length; i++) {
        max = max < scores[i] ? scores[i] : max;
        sum += scores[i];
    }
    double result = sum / max * 100.0 / (double)length;
    cout << result;
    return 0;
}