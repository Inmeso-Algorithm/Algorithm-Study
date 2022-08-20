// 문제 링크: https://www.acmicpc.net/problem/1956
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_V 401
#define INF 1e9

int v, e;
int dist[MAX_V][MAX_V];

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            dist[i][j] = INF;
        }
    }
    
    // 주어진 거리 정보를 받는다.
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    
}

void floydWarshall() {
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int getCycleMin() {
    int cycle = INF;
    
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) continue;
            if (dist[i][j] != INF && dist[j][i] != INF) {
                cycle = min(cycle, dist[i][j] + dist[j][i]);
            }
        }
    }
    
    return cycle;
}

int main() {
    init();
    floydWarshall();
    int result = getCycleMin();
    cout << (result == INF ? -1 : result);
    return 0;
}

