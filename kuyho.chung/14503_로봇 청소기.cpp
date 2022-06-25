// 문제 링크: https://www.acmicpc.net/problem/14503
#include <iostream>
using namespace std;
#define MAX_N 50

int n, m;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int r, c;   // robot's current position
int robotDirection; // 0: north, 1: east, 2: south, 3: west
int cleanCount = 0;
int br[4] = {-1, 0, 1, 0};
int bc[4] = {0, 1, 0, -1};

bool inBoundary(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < m) return true;
    return false;
}

void cleaning() {
    for (int dir = 0; dir < 4; dir++) {
        int nextDir = (robotDirection + 3 - dir) % 4;
        int nr = r + br[nextDir];
        int nc = c + bc[nextDir];
        
        // 왼쪽에 빈 공간이 없다면, 왼쪽으로 회전한다.
        if (grid[nr][nc] == 1 || !inBoundary(nr, nc)) continue;
        
        // 왼쪽의 빈 공간을 아직 청소하지 않았다면, 해당 칸으로 이동 후 청소
        if (grid[nr][nc] == 0 && !visited[nr][nc]) {
            visited[nr][nc] = true;
            r = nr; c = nc; robotDirection = nextDir;
            cleanCount++;
            cleaning();
        }
    }
    
    int backDir = (robotDirection + 2) % 4;
    int nr = r + br[backDir];
    int nc = c + bc[backDir];
    if (0 <= nr || nr <= n || 0 <= nc || nc <= m) {
        if (grid[nr][nc] == 0) {
            r = nr; c = nc; cleaning();
        }
        else {
            return;
        }
    }
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> r >> c >> robotDirection;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }
    visited[r][c] = true;
    cleanCount++;
}

int main() {
    init();
    cleaning();
    cout << cleanCount;
    return 0;
}


