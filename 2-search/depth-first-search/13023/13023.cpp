#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int> > list;
static vector<bool> visited;
static bool finished;

void DFS(int num, int depth);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N : 사람의 수, M: 친구 관계의 수
    int N, M;
    cin >> N >> M;

    list.resize(N);                    // 친구 관계 연결 리스크 크기 설정
    visited = vector<bool>(N, false);  // 방문 여부 배열 크기 설정
    finished = false;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        DFS(i, 1);
    }

    if (finished) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}

void DFS(int num, int depth) {
    if (depth == 5 || finished) {
        finished = true;
        return;
    };
    visited[num] = true;
    for (int i : list[num]) {
        if (!visited[i]) {
            DFS(i, depth + 1);
        }
    }
    visited[num] = false;
}