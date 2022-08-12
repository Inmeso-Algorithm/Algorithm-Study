// 문제 링크: https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define MAX_N 100001
#define INF 1e9

int v;
vector<pair<int, long long> > nodes[MAX_N];
long long maxDist = 0;
int endNode = -1;

void dfs(int currentNode, int dist, unordered_set<int> visited) {

	// 이미 이번 노드를 방문했다면 스킵
	if (visited.find(currentNode) != visited.end()) return;
	visited.insert(currentNode);

	// 거리 비교
	if (dist > maxDist) {
		maxDist = dist;
		endNode = currentNode;
	}

	// 연결된 모든 노드에 대해 DFS를 진행한다.
	for (auto& next : nodes[currentNode]) {
		dfs(next.first, dist + next.second, visited);
	}
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 주어진 입력을 받는다.
	cin >> v;
	for (int i = 0; i < v; i++) {
		int a, b;
		long long c;
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			nodes[a].push_back({ b, c });
		}
	}
}

int main() {
	init();
	unordered_set<int> visited;
	dfs(1, 0, visited);
	dfs(endNode, 0, visited);
	cout << maxDist;
}
