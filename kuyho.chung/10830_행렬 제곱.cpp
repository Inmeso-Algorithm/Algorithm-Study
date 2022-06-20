// 문제 링크: https://www.acmicpc.net/problem/10830
#include <iostream>
using namespace std;
#define MAX_N 5

long long n, b;

long long a[MAX_N][MAX_N];
long long ans[MAX_N][MAX_N] = { 0, };

void matrixMultiply(long long x[MAX_N][MAX_N], long long y[MAX_N][MAX_N]) {
	long long temp[MAX_N][MAX_N] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				temp[i][j] += (x[i][k] * y[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = temp[i][j];
		}
	}
}

void simulate() {
	while (b > 0) {
		if (b % 2 == 1)
			matrixMultiply(ans, a);
		matrixMultiply(a, a);
		b /= 2;
	}
}

void printArray() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> b;
	// 행렬 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}
}

int main() {
	init();
	simulate();
	printArray();
	return 0;
}
