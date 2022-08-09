// 문제 링크: https://www.acmicpc.net/problem/11657
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 501
#define INF 1e9

int n, m;
vector< pair<int, int> > graph[MAX_N];
long long dist[MAX_N];

bool getDist() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < graph[j].size(); k++) {
                int to = graph[j][k].first;
                int cost = graph[j][k].second;
                
                if (dist[j] != INF && dist[to] > dist[j] + cost) {
                    dist[to] = dist[j] + cost;
                    if (i == n) return false;
                }
            }
        }
    }
    return true;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    // 거리 배열 초기화
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    
    // 주어진 입력을 받는다.
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
}

int main() {
    init();
    if (!getDist()) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        dist[i] != INF ? cout << dist[i] << '\n' : cout << -1 << '\n';
    }
    return 0;
}

