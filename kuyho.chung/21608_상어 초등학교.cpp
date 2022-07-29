// 문제 링크: https://www.acmicpc.net/problem/21608
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;
#define MAX_N 21
#define SQR_N 401

int n;
vector<unordered_set<int> > student(SQR_N);
vector<int> studentOrder;
int classroom[MAX_N][MAX_N];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n*n; i++) {
		int x, a, b, c, d;
		cin >> x >> a >> b >> c >> d;
		student[x].insert(a);
		student[x].insert(b);
		student[x].insert(c);
		student[x].insert(d);
		studentOrder.push_back(x);
	}

	// 교실의 빈칸은 -1으로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			classroom[i][j] = -1;
		}
	}
}

bool vectorSort(vector<int> a, vector<int> b) {
	// 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	// 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
	// 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
	// 칸 주위 좋아하는 친구들의 수, 칸 주위 빈칸의 수, r, c

	if (a[0] == b[0]) {
		if (a[1] == b[1]) {
			if (a[2] == b[2]) {
				return a[3] < b[3];
			}
			return a[2] < b[2];
		}
		return a[1] > b[1];
	}
	return a[0] > b[0];
}

bool inBoundary(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) return true;
	return false;
}

// 남아있는 빈칸들의 정보를 수집한다.
vector<int> getNextSpace(unordered_set<int> &friends) {
	vector<vector<int> > spaceCandidates;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 만약 여기가 빈칸이라면, 주변 풍수지리를 체크한다.
			if (classroom[i][j] == -1) {
				int friendsFound = 0, emptySpaces = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nr = i + dx[dir];
					int nc = j + dy[dir];
					if (!inBoundary(nr, nc)) continue;
					if (friends.find(classroom[nr][nc]) != friends.end()) friendsFound++;
					else if (classroom[nr][nc] == -1) emptySpaces++;
				}
				vector<int> temp = { friendsFound, emptySpaces, i, j };
				spaceCandidates.push_back(temp);
			}
		}
	}
	sort(spaceCandidates.begin(), spaceCandidates.end(), vectorSort);

	return spaceCandidates[0];
}

void simulate() {
	for (auto& next : studentOrder) {
		vector<int> nextSpace = getNextSpace(student[next]);
		classroom[nextSpace[2]][nextSpace[3]] = next;
	}
}

int getStudentHappiness() {
	int happiness = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int friendCount = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nr = i + dx[dir];
				int nc = j + dy[dir];
				if (!inBoundary(nr, nc)) continue;
				if (student[classroom[i][j]].find(classroom[nr][nc]) != student[classroom[i][j]].end()) {
					friendCount++;
				}
			}
			
			switch (friendCount) {
			case 1:
				happiness += 1;
				break;
			case 2:
				happiness += 10;
				break;
			case 3:
				happiness += 100;
				break;
			case 4:
				happiness += 1000;
				break;
			}
		}
	}
	return happiness;
}

int main() {
	init();
	simulate();
	cout << getStudentHappiness();
	return 0;
}
