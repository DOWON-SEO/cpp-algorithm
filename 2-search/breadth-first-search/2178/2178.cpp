#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int maze[101][101];
bool visited[101][101];
bool finished = false;
int N, M;
struct coord {
    int x;
    int y;
};

void BFS(int x, int y);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 미로 배열, 방문 여부 배열 초기화
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            maze[i][j] = 0;
            visited[i][j] = false;
        }
    }

    // 미로 배열 값 설정
    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++) {
            maze[i][j] = line[j - 1] - '0';
        }
    }

    BFS(1, 1);

    cout << maze[N][M] << "\n";

    return 0;
}

void BFS(int x, int y) {
    queue<coord> myQueue;
    coord position;
    position.x = x;
    position.y = y;
    visited[x][y] = true;
    maze[x][y] = 1;
    myQueue.push(position);
    while (!myQueue.empty()) {
        coord newPosition = myQueue.front();
        myQueue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = newPosition.x + dx[i];
            int ny = newPosition.y + dy[i];
            if (nx >= 1 && ny >= 1 && nx <= N && ny <= M) {
                if (maze[nx][ny] == 1 && visited[nx][ny] == false) {
                    maze[nx][ny] = maze[newPosition.x][newPosition.y] + 1;
                    coord newCoord;
                    newCoord.x = nx;
                    newCoord.y = ny;
                    myQueue.push(newCoord);
                    visited[nx][ny] = true;
                }
            }
        }
    }
}