#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j;
    int max;
    string str;

    cin >> str;
    vector<int> list(str.size());
    for (i = 0; i < str.size(); i++) {
        list[i] = stoi(str.substr(i, 1));
    }

    int maxIndex;
    for (i = 0; i < list.size(); i++) {
        maxIndex = i;
        for (j = i + 1; j < list.size(); j++) {
            if (list[maxIndex] < list[j]) {
                maxIndex = j;
            }
        }
        swap(list[maxIndex], list[i]);
    }
    for (i = 0; i < list.size(); i++) {
        cout << list[i];
    }

    return 0;
}