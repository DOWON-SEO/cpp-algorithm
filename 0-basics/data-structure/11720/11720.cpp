// 백준 11720 (Bronze 4)

// N개의 숫자가 공백없이 쓰여 있을 때, 이 숫자를 모두 합해 출력하는 프로그램을 작성하시오.

#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    int i;

    string str;
    cin >> length >> str;
    int result = 0;
    int value = 0;
    for (i = 0; i < str.length(); i++) {
        result += str[i] - '0';
    }
    cout << result << endl;

    string a = to_string(1234);
    int inum = stoi(a);
    cout << a << inum;

    return 0;
}