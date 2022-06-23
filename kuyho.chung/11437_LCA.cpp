// 문제 링크: https://www.acmicpc.net/problem/11437
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 100001

int n, m;
vector<int> node[MAX_N];
vector<pair<int, int> > nodePair;
int parent[MAX_N][18];
int level[MAX_N];
int maxLevel;

void setTree(int childNode, int parentNode, int currentLvl) {
	level[childNode] = currentLvl;
	parent[childNode][0] = parentNode;

	for (int i = 1; i <= maxLevel; i++) {
		parent[childNode][i] = parent[parent[childNode][i - 1]][i - 1];
	}

	for (int i = 0; i < node[childNode].size(); i++) {
		int currentNode = node[childNode][i];
		if (currentNode == parentNode) continue;
		setTree(currentNode, childNode, currentLvl + 1);
	}
}

int LCA(int a, int b) {
	if (a == 1 || b == 1) return 1;

	if (level[a] < level[b]) swap(a, b);
	if (level[a] != level[b]) {
		for (int i = maxLevel; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b]) {
				a = parent[a][i];
			}
		}
	}

	int commonParent = a;
	if (a != b) {
		for (int i = maxLevel; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			commonParent = parent[a][i];
		}
	}

	return commonParent;
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		nodePair.push_back({ a, b });
	}
}

int main() {
	// 주어진 입력을 받는다.
	init();
	// 주어진 입력을 바탕으로 초기 조건을 설정한다.
	maxLevel = (int)floor(log2(MAX_N));
	setTree(1, 0, 1);
	// 주어진 노드 쌍에 대해 공통 조상을 구하여 출력한다.
	for (auto& next : nodePair) {
		cout << LCA(next.first, next.second) << '\n';
	}
	return 0;
}
