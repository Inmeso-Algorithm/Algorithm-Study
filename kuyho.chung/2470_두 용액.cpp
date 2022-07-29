// 문제 링크: https://www.acmicpc.net/problem/2470
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int n;
long long solutions[MAX_N];
int sol1, sol2;
long long val;
int head, tail;

void answer() {
    cout << solutions[sol1] << ' ' << solutions[sol2];
}

void search() {
    while (head < tail) {
        // 용액을 합쳤을 때 0에 더 가까우면
        long long temp = abs(solutions[head] + solutions[tail]);
        if (temp < abs(val)) {
            val = temp;
            sol1 = head;
            sol2 = tail;
        }
        // 합쳤을 때 더 0에 가까운 쪽으로 포인터를 옮김
        if (abs(solutions[head+1] + solutions[tail]) <= abs(solutions[head] + solutions[tail-1])) {
            head++;
        }
        else tail--;
    }
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 입력 받기
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> solutions[i];
    }
    
    // 정렬
    sort(solutions, solutions + n);
    
    // 투 포인터 초기화
    head = 0; tail = n - 1;
    
    // 기록을 위한 변수 값 초기화
    sol1 = 0;
    sol2 = n - 1;
    val = 1e11;
}

int main() {
    init();
    search();
    answer();
    return 0;
}
