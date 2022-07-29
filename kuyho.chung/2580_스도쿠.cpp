// 문제 링크: https://www.acmicpc.net/problem/2580
#include <iostream>
using namespace std;
#define MAX_N 9

int board[MAX_N][MAX_N];
bool row[MAX_N][MAX_N];
bool column[MAX_N][MAX_N];
bool boardSquare[MAX_N][MAX_N]; // [[0, 1, 2], [3, 4, 5], [6, 7, 8]]

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            int temp;
            cin >> temp;
            board[i][j] = temp;
            // 이미 숫자가 기록되어 있는 곳을 확인함
            if (temp != 0) {
                row[i][temp] = true;
                column[j][temp] = true;
                boardSquare[(i / 3) * 3 + (j / 3)][temp] = true;
            }
        }
    }
}

void printBoard() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int cnt) {
    
    if (cnt == 81) {
        printBoard();
        exit(0);
        return;
    }
    int x = cnt / MAX_N;
    int y = cnt % MAX_N;
    
    // 빈칸일 경우
    if (board[x][y] == 0) {
        for (int i = 1; i <= MAX_N; i++) {
            if (!row[x][i] && !column[y][i] && !boardSquare[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                column[y][i] = true;
                boardSquare[(x / 3) * 3 + (y / 3)][i] = true;
                board[x][y] = i;
                
                dfs(cnt + 1);
                
                row[x][i] = false;
                column[y][i] = false;
                boardSquare[(x / 3) * 3 + (y / 3)][i] = false;
                board[x][y] = 0;
            }
        }
    }
    else dfs(cnt + 1);
}

int main() {
    init();
    dfs(0);
    return 0;
}

