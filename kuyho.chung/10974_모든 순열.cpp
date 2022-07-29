// 문제 링크: https://www.acmicpc.net/problem/10974
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

int n;
set<string> combinations;

void makePermutation(string num, unordered_set<int> used) {
    // n개의 숫자로 완성된 경우
    if (num.size() == n) {
        combinations.insert(num);
        return;
    }
    
    // 아직 사용하지 않은 숫자를 이용하여 조합
    for (int i = 1; i <= n; i++) {
        // 사용하였다면 스킵
        if (used.find(i) != used.end()) continue;
        string temp = num + to_string(i);
        used.insert(i);
        makePermutation(temp, used);
        used.erase(i);
    }
}

void init() {
    // 기본 입력
    cin >> n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    // 순열을 만들기 위한 초기 조건 셋팅
    unordered_set<int> used;
    string num = "";
    for (int i = 1; i <= n; i++) {
        num += to_string(i);
        used.insert(i);
        makePermutation(num, used);
        num = "";
        used.erase(i);
    }
    
    // 순열을 공백을 포함하여 출력
    for (auto &perm : combinations) {
        for (auto &each : perm) {
            cout << each << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
