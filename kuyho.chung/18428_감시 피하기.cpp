// 문제 링크: https://www.acmicpc.net/problem/18428
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 6

int n;
char corridor[MAX_N][MAX_N];
char corridor_cpy[MAX_N][MAX_N];
vector <pair <int, int> > teachers;
vector <pair <int, int> > spaces;
bool can_hide = false;

bool can_find(int curx, int cury, int dir) {
    
        if (dir == 0) {
            int x = curx, y = cury;
            while (y >= 0) {
                if (corridor[x][y] == 'S') {
                    return true;
                }
                if (corridor[x][y] == 'O') {
                    break;
                }
                y--;
            }
        }
        if (dir == 1) {
            int x = curx, y = cury;
            while (y < n) {
                if (corridor[x][y] == 'S') {
                    return true;
                }
                if (corridor[x][y] == 'O') {
                    break;
                }
                y++;
            }
        }
        if (dir == 2) {
            int x = curx, y = cury;
            while (x >= 0) {
                if (corridor[x][y] == 'S') {
                    return true;
                }
                if (corridor[x][y] == 'O') {
                    break;
                }
                x--;
            }
        }
        if (dir == 3) {
            int x = curx, y = cury;
            while (x < n) {
                if (corridor[x][y] == 'S') {
                    return true;
                }
                if (corridor[x][y] == 'O') {
                    break;
                }
                x++;
            }
        }
    
    return false;
}

bool discover() {
    for (int i = 0; i < teachers.size(); i++) {
        for (int dir = 0; dir < 4; dir++) {
            if (can_find(teachers[i].first, teachers[i].second, dir)) {
                return true;
            }
        }
    }
    return false;
}

void dfs(int count) {
    if (count == 3) {
        if (!discover()) {
            can_hide = true;
            return;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (corridor[i][j] == 'X') {
                    count++;
                    corridor[i][j] = 'O';
                    dfs(count);
                    count--;
                    corridor[i][j] = 'X';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            cin >> temp;
            corridor[i][j] = temp;
            if (temp == 'T')
                teachers.push_back({i, j});
            if (temp == 'X')
                spaces.push_back({i, j});
        }
    }
    
    dfs(0);
    if (can_hide) cout << "YES";
    else cout << "NO";
    return 0;
}
