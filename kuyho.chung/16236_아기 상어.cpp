// 문제 링크: https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 20

int shark_size = 2, seconds = 0;
int shark_x = 0, shark_y = 0, eatcount = 0;
int min_x = 1e9, min_y = 1e9, dist = 1e9;
int visited[MAX_N][MAX_N];
int area[MAX_N][MAX_N];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = -1;
        }
    }
    min_x = 1e9; min_y = 1e9, dist = 1e9;
}

bool can_access(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    else return false;
}

void bfs(int x, int y) {
    init();
    queue<pair <int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 0;
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (!can_access(nx, ny)) continue;
            if (visited[nx][ny] != -1 || area[nx][ny] > shark_size) continue;
            
            visited[nx][ny] = visited[x][y] + 1;
            if (area[nx][ny] != 0 && area[nx][ny] < shark_size) {
                if (dist > visited[nx][ny]) {
                    min_x = nx;
                    min_y = ny;
                    dist = visited[nx][ny];
                }
                else if (dist == visited[nx][ny]) {
                    if (min_x == nx) {
                        if (min_y > ny) {
                            min_x = nx;
                            min_y = ny;
                        }
                    } else if (min_x > nx) {
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            if (area[i][j] == 9) {
                shark_x = i;
                shark_y = j;
                area[i][j] = 0;
            }
        }
    }
    
    while(1) {
        init();
        bfs(shark_x, shark_y);
        if (min_x != 1e9 && min_y != 1e9) {
            area[min_x][min_y] = 0;
            eatcount++;
            seconds += visited[min_x][min_y];
            if (eatcount == shark_size) {
                shark_size++;
                eatcount = 0;
            }
            shark_x = min_x;
            shark_y = min_y;
        }
        else break;
    }
    
    cout << seconds;
    return 0;
}
