// 문제 링크: https://www.acmicpc.net/problem/1987
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ALPH 26

int r, c;
int answer = 0;
vector<string> grid;
bool visited[ALPH];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inBoundary (int x, int y) {
    if (0 <= x && x < r && 0 <= y && y < c) return true;
    return false;
}

void dfs(int x, int y, int cnt) {
    answer = max(answer, cnt);
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (!inBoundary(nx, ny)) continue;
        if (!visited[grid[nx][ny] - 'A']) {
            visited[grid[nx][ny] - 'A'] = true;
            dfs(nx, ny, cnt + 1);
            visited[grid[nx][ny] - 'A'] = false;
        }
    }
}

void init() {
    // 기본 입력을 받는다
    cin >> r >> c;
    string temp;
    for (int i = 0; i < r; i++) {
        cin >> temp;
        grid.push_back(temp);
        temp.clear();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 기본 입력을 받는다
    init();
    
    // dfs를 통한 백트래킹 탐색
    visited[grid[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    
    // 마무리
    cout << answer;
    return 0;
}

