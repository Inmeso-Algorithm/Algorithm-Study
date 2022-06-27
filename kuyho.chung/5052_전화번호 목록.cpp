// 문제 링크: https://www.acmicpc.net/problem/5052
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tc;

bool isSubstring(string st1, string st2) {
	// st1이 더 길다면 st2의 부분문자열이 될 수 없다.
	if (st1.size() > st2.size()) return false;
	if (st1 == st2.substr(0, st1.size())) return true;
	return false;
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
}

void testCase() {
	int n;
	vector<string> words;

	// 입력을 받는다
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	// 문자열 기준 정렬
	sort(words.begin(), words.end());

	for (int i = 0; i < n - 1; i++) {
		if (isSubstring(words[i], words[i + 1])) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	init();
	while (tc--) {
		testCase();
	}
	return 0;
}
