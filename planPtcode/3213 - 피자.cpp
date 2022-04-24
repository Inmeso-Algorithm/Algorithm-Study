#include <iostream>
#include <string>
using namespace std;

int compare(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int mod(int m, int a) {		//m=��,a=�����¼�
	if (m % a == 0) {
		return m / a;
	}
	else {
		return m / a + 1;
	}
}

int main() {
	int arr[3] = { 0 };
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "1/2") {
			arr[0] += 1;
		}
		else if (s == "1/4") {
			arr[1] += 1;
		}
		else if (s == "3/4") {
			arr[2] += 1;
		}
	}
	int ans = 0;
	ans += (arr[0] / 2);
	arr[0] %= 2;
	int quarterslice = compare(arr[1], arr[2]);
	arr[1] -= quarterslice; arr[2] -= quarterslice;
	ans += quarterslice;
	//������ 1/2 1�� �Ǵ� 0��, (1/4�� 3/4)�� ������ ����
	if (arr[2] == 0) {	//(3/4)���� ����
		ans += mod( arr[0] + arr[1],4);
	}
	else {		//(1/4)���� ����
		ans += (arr[0] + arr[2]);
	}
	cout << ans;
}