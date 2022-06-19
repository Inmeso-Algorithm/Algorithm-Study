// 문제 링크: https://www.acmicpc.net/problem/11404
#include <iostream>
using namespace std;
#define MAX_N 101
#define INF 1e9

int graph[MAX_N][MAX_N];
int n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < MAX_N; i++) {
        fill (graph[i], graph[i] + MAX_N, INF);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min (graph[a][b], c);                //도시 a에서 b로 가는 비용은 c
    }
    
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) cout << 0 << " ";
            else cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
