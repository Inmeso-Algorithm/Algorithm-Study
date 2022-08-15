// 문제 링크: https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string input;
stack<char> s;

bool isAlphabet(char input) {
    if ('A' <= input && input <= 'Z') return true;
    return false;
}

bool isOperator(char input) {
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input == ')') return true;
    return false;
}

// stack의 top s가 다음 연산자 next보다 우선순위가 낮은 경우 true를 return한다.
bool isHighPriority(char s, char next) {
    if ((s == '+' || s == '-') && (next == '*' || next == '/')) return true;
    if (next == '(') return true;
    return false;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
}

void solve() {
    for (int i = 0; i < input.size(); i++) {
        // 피연산자는 그대로 출력한다.
        if (isAlphabet(input[i])) {
            cout << input[i];
            continue;
        }
        // 연산자일 경우,
        if (isOperator(input[i])) {
            // 스택이 비었으면 본인을 추가한다.
            if (s.empty()) {
                s.push(input[i]);
            }
            else {
                // 닫는 괄호일 경우, 여는 괄호가 나올 때까지 pop한다.
                if(input[i] == ')') {
                    while(s.top() != '(') {
                        cout << s.top();
                        s.pop();
                    }
                    s.pop();
                }
                // 본인보다 우선순위가 낮은 연산자가 나올때까지 pop 후 본인을 추가한다.
                else {
                    while(!isHighPriority(s.top(), input[i])) {
                        // 여는 괄호는 pop하지 않는다.
                        if (s.top() == '(') break;
                        cout << s.top();
                        s.pop();
                        if (s.empty()) break;
                    }
                    s.push(input[i]);
                }
            }
        }
    }
    
    // 나머지 연산자 출력
    while(!s.empty()) {
        if (s.top() != '(') cout << s.top();
        s.pop();
    }
}

int main() {
    init();
    solve();
    return 0;
}

