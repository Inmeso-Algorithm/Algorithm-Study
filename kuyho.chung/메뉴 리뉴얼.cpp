// 문제 링크: https://school.programmers.co.kr/learn/courses/30/lessons/72411?language=cpp
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<pair<int, string > > > answer_sub(11);
unordered_set<string> trial;

bool sub_sort(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

void combination_check(string combination, vector<unordered_set<char> > &order_set) {
    
    int count = 0;
    
    // 각 주문한 케이스에 대해, 만들어낸 조합을 포함하는 케이스가 몇 개인지 센다.
    for (int i = 0; i < order_set.size(); i++) {
        bool all_exists = true;

        for (int j = 0; j < combination.size(); j++) {
            if (order_set[i].find(combination[j]) == order_set[i].end()) {
                all_exists = false;
                break;
            }
        }
        if (all_exists) count++;
    }
    if (count >= 2) {
        sort(combination.begin(), combination.end());
        answer_sub[combination.size()].push_back({count, combination});
    }
}

void menu_combination(int j, string &orders, int course_length, unordered_set<char> visited, string combination, vector<unordered_set<char> > &order_set) {
    
    // 조합 구성이 다 되었으면, 중복 여부를 검사하고, 2번 이상 주문되었는지 확인한다.
    if (visited.size() == course_length) {
        sort(combination.begin(), combination.end());
        if (trial.find(combination) == trial.end()) {
            trial.insert(combination);
            combination_check(combination, order_set);
            return;
        }
    }
    else if (visited.size() > orders.size()) return;
    
    // 조합 구성을 마저 한다.
    else {
        string nextCombination = combination;
        for (int i = j; i < orders.size(); i++) {
            char current = orders[i];
            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                nextCombination += current;
                menu_combination(i, orders, course_length, visited, nextCombination, order_set);
                visited.erase(current);
                nextCombination = combination;
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<unordered_set<char> > order_set(orders.size());
    
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            order_set[i].insert(orders[i][j]);
        }
    }
    
    // i번 주문된 단품메뉴 조합을 찾는다.
    for (int i = 0; i < course.size(); i++) {
        unordered_set<char> visited;
        string combination = "";
        
        for (int a = 0; a < orders.size(); a++) {
            for (int j = 0; j < orders[a].size(); j++) {
                visited.insert(orders[a][j]);
                combination += orders[a][j];
                // i개의 단품메뉴로 이루는 조합 구성 시작
                menu_combination(j, orders[a], course[i], visited, combination, order_set);
                visited.erase(orders[a][j]);
                combination = "";
            }
        }
    }
    
    vector<string> answer;
    
    for (int i = 0; i < course.size(); i++) {
        sort(answer_sub[course[i]].begin(), answer_sub[course[i]].end(), sub_sort);
        int most_ordered = answer_sub[course[i]][0].first;
        for (int j = 0; j < answer_sub[course[i]].size(); j++) {
            if (answer_sub[course[i]][j].first == most_ordered) {
                answer.push_back(answer_sub[course[i]][j].second);
            }
            else break;
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
