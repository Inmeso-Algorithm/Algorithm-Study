// 문제 링크: https://www.acmicpc.net/problem/14502
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 8

int lab[MAX_N][MAX_N];
int lab_copy[MAX_N][MAX_N];
int n, m, safe_area = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int get_safe_area() {
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab_copy[i][j] == 0)
                area++;
        }
    }
    return area;
}

bool boundary_check (int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    else return false;
}

void virus_spread(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (lab_copy[nx][ny] == 0 && boundary_check(nx, ny)) {
            lab_copy[nx][ny] = 2;
            virus_spread(nx, ny);
        }
    }
}

void dfs(int count) {
    if (count == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                lab_copy[i][j] = lab[i][j];
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lab_copy[i][j] == 2)
                    virus_spread(i, j);
            }
        }
        safe_area = max(safe_area, get_safe_area());
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lab[i][j] == 0) {
                    count++;
                    lab[i][j] = 1;
                    dfs(count);
                    count--;
                    lab[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }
    
    dfs(0);
    cout << safe_area;
    return 0;
}
