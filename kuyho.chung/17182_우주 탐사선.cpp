// 문제 링크: https://www.acmicpc.net/problem/17182
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;
#define MAX_N 11
#define INF 1e9

//int grid[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int n, k;

int totalDist = INF;

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void dfs(int current, int distance, unordered_set<int> visited) {
    if (totalDist < distance) return;
    if (visited.size() == n) {
        totalDist = min(totalDist, distance);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited.find(i) != visited.end()) continue;
        visited.insert(i);
        dfs(i, distance + dist[current][i], visited);
        visited.erase(i);
    }
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 거리 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }
    // 주어지는 입력을 받는다.
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
}

int main() {
    init();
    floydWarshall();
    
    unordered_set<int> visited;
    visited.insert(k);
    dfs(k, 0, visited);
    cout << totalDist;
}

