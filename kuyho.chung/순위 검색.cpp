// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int> > > > > db;
vector<vector<string> > vals = {{"cpp", "java", "python"}, {"backend", "frontend"}, {"junior", "senior"}, {"chicken", "pizza"}};
vector<int> answer;

void dbInit() {
    vector<int> score;
    
    unordered_map<string, vector<int> > food;
    food.insert({"chicken", score});
    food.insert({"pizza", score});
    
    unordered_map<string, unordered_map<string, vector<int> > > exp;
    exp.insert({"junior", food});
    exp.insert({"senior", food});
    
    unordered_map<string, unordered_map<string, unordered_map<string, vector<int> > > > group;
    group.insert({"backend", exp});
    group.insert({"frontend", exp});
    
    db.insert({"cpp", group});
    db.insert({"java", group});
    db.insert({"python", group});

    return;
}

void dbSort() {
    for (int a = 0; a < vals[0].size(); a++) {
        for (int b = 0; b < vals[1].size(); b++) {
            for (int c = 0; c < vals[2].size(); c++) {
                for (int d = 0; d < vals[3].size(); d++) {
                    sort(db[vals[0][a]][vals[1][b]][vals[2][c]][vals[3][d]].begin(), db[vals[0][a]][vals[1][b]][vals[2][c]][vals[3][d]].end());
                }
            }
        }
    }
}

//score 이상 원소 수를 센다
int moreThan(vector<int> &nums, int score) {
    
    if (nums.size() == 0) {
        return 0;
    }
    
    int pos = lower_bound(nums.begin(), nums.end(), score) - nums.begin();
    return nums.size() - pos;
}

int dfs (vector<string> &queryIn, vector<string> queryOut) {
    // 쿼리를 완성하였다.
    int ans = 0;
    if (queryOut.size() == 5) {
        ans += moreThan(db[queryOut[0]][queryOut[1]][queryOut[2]][queryOut[3]], stoi(queryIn[4]));
    }
    else {
        int nextIter = queryOut.size();
        if (queryIn[nextIter] == "-") {
            for (auto &next : vals[nextIter]) {
                queryOut.push_back(next);
                ans += dfs(queryIn, queryOut);
                queryOut.pop_back();
            }
        }
        else {
            queryOut.push_back(queryIn[nextIter]);
            ans += dfs(queryIn, queryOut);
        }
    }
    return ans;
}

void queryInsert(vector<string> &result) {
    db[result[0]][result[1]][result[2]][result[3]].push_back(stoi(result[4]));
}

void findUser(vector<string> &result) {
    vector<string> queryOut;
    int score = dfs(result, queryOut);
    answer.push_back(score);
}

vector<int> solution(vector<string> info, vector<string> query) {
    
    dbInit();
    
    // info를 파싱하여 db에 삽입
    for (auto &next : info) {
        istringstream ss(next);
        string buffer;
        vector<string> result;
        
        while(getline(ss, buffer, ' ')) {
            result.push_back(buffer);
        }
        
        queryInsert(result);
    }
    
    // 각 점수 정렬
    dbSort();
    
    // 각 조건에 맞게 검색
    for (auto &next : query) {
        istringstream ss(next);
        string buffer;
        vector<string> result;
        
        while(getline(ss, buffer, ' ')) {
            if (buffer != "and")
                result.push_back(buffer);
        }
        
        findUser(result);
    }
    
    return answer;
}
