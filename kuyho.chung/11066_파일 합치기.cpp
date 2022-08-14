// 문제 링크: https://www.acmicpc.net/problem/11066
#include <iostream>
using namespace std;
#define MAX_K 501
#define INF 1e9

int t, k;
int sum[MAX_K];
int file[MAX_K];
int dp[MAX_K][MAX_K];

void getDp() {
	for (int range = 1; range <= k; range++) {
		for (int start = 1; start <= k - range; start++) {
			dp[start][range + start] = INF;
			for (int div = start; div < range + start; div++) {
				int origin = dp[start][range + start];
				int diff = dp[start][div] + dp[div + 1][range + start] + sum[range + start] - sum[start - 1];
				dp[start][range + start] = min(origin, diff);
			}
		}
	}
}

void input() {
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> file[i];
		sum[i] = sum[i - 1] + file[i];
	}
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
}

int main() {
	init();
	while (t--) {
		input();
		getDp();
		cout << dp[1][k] << '\n';
	}
}
