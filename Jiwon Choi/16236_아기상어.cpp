#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

class Pair { // 좌표 순서쌍을 저장해줄 Pair 클래스
public:
	int x;
	int y;

	Pair(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Pair() {
		this->x = -1;
		this->y = -1;
	}
	void assign(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool empty() {
		if (this->x == -1 || this->y == -1) return true;
		else return false;
	}
	void clear() {
		this->x = -1;
		this->y = -1;
	}
};

int shark_size = 2, fish_count = 0, timer = 0;

int** grid; // 바다의 상황을 저장할 2차원배열 포인터 grid
int** dist; // 거리를 계산할 2차원배열 포인터 dist

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

Pair shark_loc; // 상어의 위치를 저장할 Pair 객체
Pair fish_loc; // 다음에 먹을 물고기를 저장할 Pair 객체, 먹을 물고기가 없으면 (-1, -1)로 초기화됨

bool invalid_index(int x, int y, int n) {
	if (x < 0 || x == n || y < 0 || y == n) return true;
	else return false;
}

void bfs(Pair start_loc, int n) {
	queue<Pair> queue;
	dist[start_loc.x][start_loc.y] = 0;
	queue.push(start_loc);

	while (!queue.empty()) {
		Pair current = queue.front();

		if (grid[current.x][current.y] < shark_size && grid[current.x][current.y] != 0) {
			if (fish_loc.empty()) {
				fish_loc = current;
			}
			else if (dist[fish_loc.x][fish_loc.y] > dist[current.x][current.y]) {
				fish_loc = current;
			}
			else if (dist[fish_loc.x][fish_loc.y] == dist[current.x][current.y]) {
				if (fish_loc.x > current.x) {
					fish_loc = current;
				}
				else if (fish_loc.x == current.x && fish_loc.y > current.y) {
					fish_loc = current;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = current.x + dx[i];
			int ny = current.y + dy[i];

			if (invalid_index(nx, ny, n)) continue;
			if (dist[nx][ny] != MAX || grid[nx][ny] > shark_size) continue;

			dist[nx][ny] = dist[current.x][current.y] + 1;
			Pair next_loc(nx, ny);
			queue.push(next_loc);
		}
		queue.pop();
	}
}

void clear(int n) { //dist 2차원 배열을 초기화해주는 함수
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			dist[i][k] = MAX;
		}
	}
}

int main() {
	int n, v; //n은 grid의 크기, v는 grid각각의 value
	cin >> n;

	grid = new int* [n]; // grid와 dist 동적 할당으로 2차원 배열을 만듬
	dist = new int* [n];
	for (int i = 0; i < n; i++) {
		grid[i] = new int[n];
		dist[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> v;
			if (v == 9) {
				shark_loc.assign(i, k); // 상어의 위치를 미리 찾아서 bfs 시 넘겨줄 예정
			}
			grid[i][k] = v;
		}
	}

	while (10) {
		clear(n);
		bfs(shark_loc, n);
		if (fish_loc.empty()) break;

		fish_count++;
		if (fish_count == shark_size) {
			shark_size++;
			fish_count = 0;
		}

		timer += dist[fish_loc.x][fish_loc.y];
		grid[fish_loc.x][fish_loc.y] = 9;
		grid[shark_loc.x][shark_loc.y] = 0;
		shark_loc = fish_loc;
		fish_loc.clear();
	}
	cout << timer;

	return 0;
}
