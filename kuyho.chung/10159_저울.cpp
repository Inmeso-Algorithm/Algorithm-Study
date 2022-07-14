// 문제 링크: https://www.acmicpc.net/problem/10159
#include <iostream>
using namespace std;
#define MAX_N 101

int n, m;
int grid[MAX_N][MAX_N];

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 문제에서 주어진 입력을 받는다.
    cin >> n >> m;
    
    // 두 물건 간 비교 결과를 입력한다.
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // 더 무거운 쪽은 1, 더 가벼운 쪽은 -1로 초기화한다
        grid[a][b] = 1;
        grid[b][a] = -1;
    }
}

void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 거쳐서 갈 수 있고, 0이 아니면
                if (grid[i][k] == grid[k][j] && grid[i][k] != 0) {
                    grid[i][j] = grid[i][k];
                }
            }
        }
    }
}

void getResult() {
    for (int i = 1; i <= n; i++) {
        int answer = n - 1;
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] != 0) answer--;
        }
        cout << answer << '\n';
    }
}

int main() {
    init();
    floydWarshall();
    getResult();
    return 0;
}

