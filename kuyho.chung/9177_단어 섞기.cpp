// 문제 링크: https://www.acmicpc.net/problem/9177
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tc;

void eachCase() {
	for (int t = 1; t <= tc; t++) {
		string a, b, c;
		cin >> a >> b >> c;

		int left = a.size(), right = b.size();
		vector<vector<bool> > memo(left + 1, vector<bool>(right + 1, false));
		memo[0][0] = true;

		for (int i = 1; i <= left; i++) {
			memo[i][0] = (a[i - 1] == c[i - 1]) ? memo[i - 1][0] : false;  
		}
		for (int i = 1; i <= right; i++) {
			memo[0][i] = (b[i - 1] == c[i - 1]) ? memo[0][i - 1] : false;
		}
		for (int i = 1; i <= left; i++) {
			for (int j = 1; j <= right; j++) {
				char x = a[i - 1], y = b[j - 1], z = c[i + j - 1];
				if (x != z && y != z) {
					memo[i][j] = false;
					continue;
				}
				if (x == z && y != z) {
					memo[i][j] = memo[i - 1][j];
					continue;
				}
				if (x != z && y == z) {
					memo[i][j] = memo[i][j - 1];
					continue;
				}
				memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
			}
		}

		cout << "Data set " << t << ": ";
		memo[left][right] ? cout << "yes" : cout << "no";
		cout << '\n';
	}
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> tc;
}

int main() {
	init();
	eachCase();
	return 0;
}
