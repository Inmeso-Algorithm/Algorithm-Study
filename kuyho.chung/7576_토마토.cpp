// 문제 링크: https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int m, n;
int grid[MAX_N][MAX_N];
queue<pair<pair<int, int>, int > > q;	//{{x, y}, 익은 시간}

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool inBoundary(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < m) return true;
	return false;
}

void init() {
	// 문제의 조건에 맞는 입력을 받는다.
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			// 입력을 받은 곳이 익은 토마토라면 enqueue
			if (grid[i][j] == 1) {
				q.push({ {i, j}, 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();

	// 토마토를 꺼내어, 상하좌우를 확인
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int deg = q.front().second;
		q.pop();

		// 상하좌우를 확인
		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (!inBoundary(nx, ny)) continue;
			if (grid[nx][ny] == -1) continue;
			// 인접한 토마토가 아직 익지 않았다면
			if (grid[nx][ny] == 0 || grid[nx][ny] > grid[cx][cy] + 1) {
				grid[nx][ny] = deg + 1;
				q.push({ { nx, ny }, deg + 1 });
				
			}
		}
	}

	int answer = 0;
	// 모든 토마토가 다 익지 못했다면 -1을 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				cout << -1;
				return 0;
			}
			answer = max(answer, grid[i][j]);
		}
	}

	// 가장 나중에 다 익은 토마토의 시간을 출력
	cout << answer - 1;
	return 0;
}
