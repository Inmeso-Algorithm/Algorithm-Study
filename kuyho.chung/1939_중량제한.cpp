// 문제 링크: https://www.acmicpc.net/problem/1939
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define MAX_N 10001

int n, m;
vector<vector<pair <int, int> > > nodes(MAX_N); // [a] = {b, c}
int x, y;
int maxWeight;
int answer = 0;

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		nodes[a].push_back({ b, c });
		nodes[b].push_back({ a, c });
		maxWeight = max(maxWeight, c);
	}
	cin >> x >> y;
}

bool bfs(int weightLimit) {
	unordered_set<int> visited;
	queue<int> q;
	visited.insert(x);
	q.push(x);

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();

		if (currentNode == y) return true;

		for (auto& next : nodes[currentNode]) {
			// 이미 방문했으면 넘어간다.
			if (visited.find(next.first) != visited.end()) continue;
			// 현재의 중량 제한으로 다리를 건널 수 있는지 확인
			if (weightLimit <= next.second) {
				visited.insert(next.first);
				q.push(next.first);
			}
		}
	}
	return false;
}

void simulate() {
	int start = 0, end = maxWeight;
	
	// binary search
	while (start <= end) {
		int mid = (start + end) / 2;
		if (bfs(mid)) start = mid + 1;
		else end = mid - 1;
	}
	cout << end;
}

int main() {
	init();
	simulate();
	return 0;
}
