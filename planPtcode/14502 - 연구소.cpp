#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[8][8];		//초기 지도
int field[8][8];	//계산이 이루어질 지도
int visit[8][8];	//방문 여부
int N, M;	//가로 세로
int dx[4] = { 1,-1,0,0 };	//x방향 이동
int dy[4] = { 0,0,-1,1 };	//y방향 이동
int safesize;	//안전구역의 크기
int maxsafe;	//경우별 최대 안전구역의 크기
struct coor {	//좌표를 저장할 구조체
	int x, y;
};
coor Virus[10];	//바이러스의 위치를 저장
int Vidx;	//바이러스의 갯수

void Input() {		//입력을 받는 함수
	cin >> N >> M;
	safesize = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				safesize -= 1;
				if (map[i][j] == 2) {	//바이러스일 경우 저장
					Virus[Vidx] = { j,i };
					Vidx += 1;
				}
			}
		}
	}
}

void BFS() {
	int tmp = safesize;
	int next[8][8];
	queue<coor>q;	//바이러스가 들어갈 큐
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			next[i][j] = field[i][j];
			visit[i][j] = false;
		}
		for (int k = 0; k < Vidx; k++) {
			q.push(Virus[k]);
			visit[Virus[k].y][Virus[k].x] = true;
		}
	}
	while (!q.empty()) {
		coor cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && next[ny][nx] == 0) {	//지도를 벗어나지 않고 0인 경우
				if (!visit[ny][nx]) {
					next[ny][nx] = 2;
					visit[ny][nx] = true;
					tmp -= 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	if (maxsafe < tmp) {
		maxsafe = tmp;
	}
}

void wall(int cnt) {	//벽을 세우는 함수
	if (cnt == 3) {		//벽이 3개가 세워졌을때 BFS를 이용해 안전구역 계산
		BFS();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 0) {
				field[i][j] = 1;
				safesize -= 1;
				wall(cnt + 1);
				field[i][j] = 0;
				safesize += 1;
			}
		}
	}
}

void solution() {	//수행을 하는 함수
	Input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < N; k++) {	//map 복사
					for (int l = 0; l < M; l++) {
						field[k][l] = map[k][l];
					}
				}
				field[i][j] = 1;	//벽 세워보기
				safesize -= 1;
				wall(1);
				field[i][j] = 0;
				safesize += 1;
			}
		}
	}
	cout << maxsafe << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solution();
}