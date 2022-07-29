// 문제 링크: https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX_N 101

int N, M;
string maze[MAX_N];
int visited[MAX_N][MAX_N] = {0, };
int counter[MAX_N][MAX_N] = {0, };

int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};

pair<int, int> position = make_pair(0,0);

void bfs(int x, int y) {
    queue< pair<int, int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dx = x + moveX[i];
            int dy = y + moveY[i];
            if (dx < 0 || dx >= N || dy < 0 || dy >= M)
                continue;
            if (visited[dx][dy] == 1 || maze[dx][dy] == '0')
                continue;
            visited[dx][dy] = 1;
            q.push(make_pair(dx,dy));
            counter[dx][dy] = counter[x][y] + 1;
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    bfs(position.first, position.second);
    cout << counter[N-1][M-1] + 1;

    return 0;
}
