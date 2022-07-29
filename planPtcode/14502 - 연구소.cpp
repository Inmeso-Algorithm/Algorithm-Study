#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[8][8];		//�ʱ� ����
int field[8][8];	//����� �̷���� ����
int visit[8][8];	//�湮 ����
int N, M;	//���� ����
int dx[4] = { 1,-1,0,0 };	//x���� �̵�
int dy[4] = { 0,0,-1,1 };	//y���� �̵�
int safesize;	//���������� ũ��
int maxsafe;	//��캰 �ִ� ���������� ũ��
struct coor {	//��ǥ�� ������ ����ü
	int x, y;
};
coor Virus[10];	//���̷����� ��ġ�� ����
int Vidx;	//���̷����� ����

void Input() {		//�Է��� �޴� �Լ�
	cin >> N >> M;
	safesize = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				safesize -= 1;
				if (map[i][j] == 2) {	//���̷����� ��� ����
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
	queue<coor>q;	//���̷����� �� ť
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
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && next[ny][nx] == 0) {	//������ ����� �ʰ� 0�� ���
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

void wall(int cnt) {	//���� ����� �Լ�
	if (cnt == 3) {		//���� 3���� ���������� BFS�� �̿��� �������� ���
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

void solution() {	//������ �ϴ� �Լ�
	Input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < N; k++) {	//map ����
					for (int l = 0; l < M; l++) {
						field[k][l] = map[k][l];
					}
				}
				field[i][j] = 1;	//�� ��������
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