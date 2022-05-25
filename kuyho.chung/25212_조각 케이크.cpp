// 문제 링크: https://www.acmicpc.net/problem/25212
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
int answer = 0;
vector<int> cakes;

void canMakeOneCake(vector<int> pieces) {
	double sum = 0.0;
	for (auto& next : pieces) {
		sum += (1 / (double)next);
	}
	if (0.99 <= sum && sum <= 1.01) answer++;
	return;


}

void makeCombinations(int totalPiece, vector<int> pieces, unordered_set<int> included, int prev) {
	// 케이크 조각의  개수를 만족한 경우
	if (pieces.size() == totalPiece) {
		canMakeOneCake(pieces);
		return;
	}
	// 그렇지 않은 경우
	for (int i = prev; i < n; i++) {
		// 아직 이 조각을 포함하지 않은 경우
		if (included.find(i) == included.end()) {
			pieces.push_back(cakes[i]);
			included.insert(i);
			makeCombinations(totalPiece, pieces, included, i);
			pieces.pop_back();
			included.erase(i);
		}
	}
}

void numberOfPieces() {
	vector<int> pieces;
	unordered_set<int> included;
	// 원소를 1개부터 n개까지 가지는 부분집합을 탐색
	for (int i = 1; i <= n; i++) {
		makeCombinations(i, pieces, included, 0);
	}
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 문제에서 주어진 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cakes.push_back(temp);
	}
}

int main() {
	// 주어진 입력을 받아 환경을 셋팅한다.
	init();
	// 케익의 조각들의 집합의 모든 부분집합 (공집합 제외)을 구한다.
	numberOfPieces();
	// 정답 출력
	cout << answer;
	return 0;
}
