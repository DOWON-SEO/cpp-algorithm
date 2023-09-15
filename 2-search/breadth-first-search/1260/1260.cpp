#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static vector<vector<int> > list;
static vector<bool> visited;

void DFS(int num);
void BFS(int num);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;

    list.resize(n + 1);
    visited = vector<bool>(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(list[i].begin(), list[i].end());
    }

    // DFS
    visited[v] = true;
    cout << v << " ";
    DFS(v);

    visited.assign(n + 1, false);

    cout << '\n';

    BFS(v);

    return 0;
}

void DFS(int num) {
    for (int i : list[num]) {
        if (!visited[i]) {
            visited[i] = true;
            cout << i << " ";
            DFS(i);
        }
    }
}

void BFS(int num) {
    queue<int> myQueue;
    visited[num] = true;
    myQueue.push(num);
    while (myQueue.size() != 0) {
        int value = myQueue.front();
        myQueue.pop();
        cout << value << " ";
        for (int i : list[value]) {
            if (!visited[i]) {
                visited[i] = true;
                myQueue.push(i);
            }
        }
    }
}