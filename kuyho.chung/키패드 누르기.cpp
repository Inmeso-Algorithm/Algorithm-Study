// 문제 링크: https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDistance (int start, int to) {
    int to_row = to / 3;
    int to_column = to % 3;
    
    int start_row = start / 3;
    int start_column = start % 3;
    
    return (abs(start_row - to_row) + abs(start_column - to_column));
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 초기 각 손의 엄지의 위치
    /*
    0 1 2
    3 4 5
    6 7 8
    9 10 11
    */
    int left = 9, right = 11;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) numbers[i] = 10;
        else numbers[i]--;
        
        int numberVal = numbers[i] % 3;
        switch (numberVal) {
            case 0:
                answer += "L";
                left = numbers[i];
                break;
            case 2:
                answer += "R";
                right = numbers[i];
                break;
            case 1:
                int leftDist = getDistance(left, numbers[i]);
                int rightDist = getDistance(right, numbers[i]);
                
                if (leftDist < rightDist) {
                    answer += "L";
                    left = numbers[i];
                }
                if (leftDist > rightDist) {
                    answer += "R";
                    right = numbers[i];
                }
                if (leftDist == rightDist) {
                    if (hand == "left") {
                        answer += "L";
                        left = numbers[i];
                    }
                    if (hand == "right") {
                        answer += "R";
                        right = numbers[i];
                    }
                }
                break;
        }
    }
    
    return answer;
}
