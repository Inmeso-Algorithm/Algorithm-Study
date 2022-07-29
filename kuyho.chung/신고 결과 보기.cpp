// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/92334
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    vector<int> answer(id_list.size(), 0);
    
    unordered_map <string, int> id_list_dict;
    for(int i = 0; i < id_list.size(); i++) {
        id_list_dict[id_list[i]] = i;
    }
    
    unordered_map <string, set<string> > reportedMap;
    for(auto &next : report) {
        
        string from, to;
        for (int i = 0; i < next.size(); i++) {
            if (next[i] == ' ') {
                from = next.substr(0, i);
                to = next.substr(i+1);
            }
        }

        reportedMap[to].insert(from);
    }
    
    for (auto &next : reportedMap) {
        if (next.second.size() >= k) {
            for (auto &list : next.second) {
                int pos = id_list_dict[list];                
                answer[pos]++;
            }            
        }
    }    
    
    return answer;
}
