#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string str;

    cin >> str;

    string num = "";
    bool isPositive = true;

    int positive = 0;
    int negative = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '+' && str[i] != '-') {
            num += str[i];
        } else if (str[i] == '+') {
            isPositive ? positive += stoi(num) : negative += stoi(num);
            num = "";
        } else if (str[i] == '-') {
            isPositive ? positive += stoi(num) : negative += stoi(num);
            isPositive = false;
            num = "";
        }
    }
    isPositive ? positive += stoi(num) : negative += stoi(num);

    cout << positive - negative;
}
