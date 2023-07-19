#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    int start = 1;
    int end = 1;
    int sum = end + (start - 1);
    int count = 1;

    while (end != N) {  // end 포인터가 마지막에 도달하면 종료
        if (sum < N) {  // 목표한 수보다 작을 경우 end 포인터 증가 (숫자 더하기)
            sum += ++end;
        } else if (sum > N) {  // 목표한 수보다 클 경우 start 포인터 증가 (숫자 빼기)
            sum -= start++;
        } else if (sum == N) {  // 목표한 수와 같을 경우 정답 카운트 1 증가, 그리고 end 포인트 증가시킨 뒤 마지막에 도달할 때까지 계속 연산 반복
            count++;
            sum += ++end;
        }
    }
    cout << count;

    return 0;
}