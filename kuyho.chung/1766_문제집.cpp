// 문제 링크: https://www.acmicpc.net/problem/1766
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> result;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 주어진 입력을 받는다.
    cin >> n >> m;
    // 1 ~ n까지의 숫자의 진입차수를 0으로 초기화한다.
    vector<int> indegree(n+1, 0);
    vector<vector<int> > graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;  // a번 문제는 b번 문제보다 먼저 푸는 것이 좋다. b의 indegree 추가, a->b 간선 추가
        indegree[b]++;
        graph[a].push_back(b); // 노드 a가 가리키는 노드 b
    }
    
    // topology sort
    priority_queue<int> q;
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            temp.push_back(i);
        }
    }
    sort(temp.begin(), temp.end()); // 같은 indegree를 가진다면 낮은 숫자가 우선순위를 가진다.
    for (auto &next: temp) {
        q.push(-next);
    }
    
    while(!q.empty()) {
        int now = -1 * q.top();
        q.pop();
        result.push_back(now);
        
        vector<int> temp;
        for (int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]]--;
            if (indegree[graph[now][i]] == 0) {
                temp.push_back(graph[now][i]);
            }
        }
        sort(temp.begin(), temp.end()); // 같은 indegree를 가진다면 낮은 숫자가 우선순위를 가진다.
        for (auto &next: temp) {
            q.push(-next);
        }
    }
    
    // 정답 출력
    for (auto &next : result) {
        cout << next << ' ';
    }
    return 0;
}

