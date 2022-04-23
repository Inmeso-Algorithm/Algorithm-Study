// 문제 출처: https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int length = s.size();
    int answer = length;
    
    for (int i = 1; i < length/2 + 1; i++) {
        string now = "";
        string prev = s.substr(0, i);
        int cnt = 1;
        for (int j = i; j < length; j+=i) {
            string next = s.substr(j, i);
            if (prev == next) {
                cnt++;
            }
            else {
                if (cnt >= 2)
                    now += to_string(cnt);
                now += prev;
                prev = next;
                cnt = 1;
            }
        }
        if (cnt >= 2)
            now += to_string(cnt);
        now += prev;
        answer = min (answer, (int)now.size());
    }

    return answer;
}