// 문제 링크: https://www.acmicpc.net/problem/25206
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#define MAX_IN 20

double credits, grades;

double gradeToScore(string input) {
	if (input == "A+") return 4.5;
	if (input == "A0") return 4.0;
	if (input == "B+") return 3.5;
	if (input == "B0") return 3.0;
	if (input == "C+") return 2.5;
	if (input == "C0") return 2.0;
	if (input == "D+") return 1.5;
	if (input == "D0") return 1.0;
	if (input == "F") return 0.0;
	return -1.0;
}

double getFinalscore() {
	return grades / credits;
}

void init() {
	credits = 0.0, grades = 0.0;
	string subjectName, grade;
	double credit;
	for (int i = 0; i < MAX_IN; i++) {
		cin >> subjectName >> credit >> grade;
		if (grade == "P") continue;
		credits += credit;
		grades += (credit * gradeToScore(grade));
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 입력 받기
	init();
	// 점수 계산
	cout << setprecision(7) << getFinalscore() << fixed;;
	return 0;
}
