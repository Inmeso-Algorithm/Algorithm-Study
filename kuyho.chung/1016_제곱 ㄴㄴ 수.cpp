// 문제 링크: https://www.acmicpc.net/problem/1016
#include <iostream>
#include <vector>
using namespace std;

long long minVal, maxVal;

void cntNotPrime() {
	long long answer = maxVal - minVal + 1;
	vector<bool> record(maxVal - minVal + 1, false);

	// 첫 제곱수는 2^2
	long long i = 2;

	while (i * i <= maxVal) {
		// 처음으로 i^2 로 나누어 떨어지는 수를 찾는다.
		long long divNumber = minVal / (i * i);
		if (minVal % (i * i) != 0) divNumber++;

		while (divNumber * (i * i) <= maxVal) {
			if (!record[divNumber * (i * i) - minVal]) {
				record[divNumber * (i * i) - minVal] = true;
				answer--;
			}
			divNumber++;
		}
		i++;
	}

	cout << answer;
}

void init() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> minVal >> maxVal;
}

int main() {
	init();
	cntNotPrime();

	return 0;
}
