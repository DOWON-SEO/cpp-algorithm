#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFS(int v);

static vector<vector<int> > list;  // 연결 리스트의 역할
static vector<bool> visited;       // 방문 여부 확인 배열

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 수, 엣지 수 입력받기
    int nodeCount, edgeCount;
    cin >> nodeCount >> edgeCount;

    list.resize(nodeCount + 1);         // 연결리스트 크기 재조정
    visited = vector<bool>(nodeCount);  // 방문 여부 재조정

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);  // 연결리스트 추가
        list[b].push_back(a);  // 연결리스트 추가
    }

    int count = 0;

    for (int i = 1; i <= nodeCount; i++) {
        if (!visited[i]) {  // 방문하지 않았을 경우
            count++;        // 카운트 +1
            DFS(i);         // 재귀적 DFS 시작
        }
    }
    cout << count;

    return 0;
}

void DFS(int v) {
    if (visited[v]) {  // 방문 한 곳일 경우
        return;        // 종료
    }
    visited[v] = true;

    for (int i : list[v]) {         // list[v] 안의 모든 값에 대해 반복하면서
        if (visited[i] == false) {  // 방문하지 않았을 경우
            DFS(i);                 // DFS 시작
        }
    }
}
