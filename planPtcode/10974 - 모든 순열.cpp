#include <iostream>
using namespace std;
//백트래킹
int N;	//1부터 N까지
int check[8];	//방문했던 번호 저장
bool visited[8] = { false, };	//방문 여부

void solve(int cnt) {	// 순환 함수를 이용
	if (cnt == N) {	//N번째 번호까지 방문했을 때
		for (int i = 0; i < N; i++) {	//출력하기
			cout << check[i] + 1 << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++) {	//한 차례당 1부터 N까지 전부 체크
		if (!visited[i]) {	// i번을 방문하지 않았을때
			check[cnt] = i;	// cnt번째 칸에 i 저장
			visited[i] = true;	//방문했다는 표시
			solve(cnt + 1);	//cnt+1 번째 방문
			visited[i] = false;	//이전단계로 돌아와 다음 번호 탐색
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N;
	solve(0);
}