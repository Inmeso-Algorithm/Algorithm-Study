//문제 링크: https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 101

int n, k, l;
int board[MAX_N][MAX_N];
queue <pair <int, char> > rotation;
int timer = 0;
int xpos = 1, ypos = 1, dir = 0; //뱀의 머리의 x좌표, y좌표, 방향; 우하좌상 0123
int snake_length = 1;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void snake_move_elapsed() {
    board[xpos][ypos]++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] > 0)
                board[i][j]--;
        }
    }
}

void snake_move_action() {
    xpos += dx[dir];
    ypos += dy[dir];
    board[xpos][ypos] = snake_length;
}

int snake_prior_check() {
    int temp_x = xpos + dx[dir];
    int temp_y = ypos + dy[dir];
    
    if (board[temp_x][temp_y] > 0)                      //이미 뱀이 위치하여 머리와 충돌
        return 2;
    else if (temp_x < 1 || temp_y < 1 || temp_x > n || temp_y > n) //벽에 부딪힘
        return 2;
    else if (board[temp_x][temp_y] == -1)                 //사과가 있음
        return 1;
    else                                                //사과가 없음
        return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    
    //사과의 위치를 -1로 기록함
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = -1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        rotation.push(make_pair(-time, dir));
    }
    
    board[1][1] = 1;
    
    for (int i = 0; i < n*n; i++) {
        
        if (snake_prior_check() == 2) {
            cout << timer + 1;
            break;
        }
        else if (snake_prior_check() == 1)
        {
            snake_length++;
            snake_move_action();
        }
        else {
            snake_move_action();
            snake_move_elapsed();
        }
        
        timer++;
        int next_dir = -rotation.front().first;
        if (timer == next_dir) {
            char dir_change = rotation.front().second;
            rotation.pop();
            if (dir_change == 'L') {
                dir--;
                if (dir == -1) dir = 3;
            }
            else if (dir_change == 'D')
                dir = (dir + 1) % 4;
        }
        
    }
    return 0;
}
