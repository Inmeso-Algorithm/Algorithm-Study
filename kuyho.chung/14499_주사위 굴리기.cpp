// 문제 링크: https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int x, y;
int k;
int dice[6] = {0, };
int dy[5] = {0, 1, -1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
vector<vector<int> > grid;
vector<int> order;

bool inBoundary (int cx, int cy) {
    if (0 <= cx && cx < n && 0 <= cy && cy < m) return true;
    else return false;
}

// 주사위 조작 함수
//왼쪽으로 굴림
void rollLeft() {
    int one = dice[4];
    int five = dice[1];
    int zero = dice[5];
    int four = dice[0];
    
    dice[0] = zero;
    dice[1] = one;
    dice[4] = four;
    dice[5] = five;
    return;
}

void rollRight() {
    int zero = dice[4];
    int five = dice[0];
    int one = dice[5];
    int four = dice[1];
    
    dice[0] = zero;
    dice[1] = one;
    dice[4] = four;
    dice[5] = five;
    return;
}

void rollUp() {
    int zero = dice[3];
    int two = dice[0];
    int one = dice[2];
    int three = dice[1];
    
    dice[0] = zero;
    dice[1] = one;
    dice[2] = two;
    dice[3] = three;
    return;
}

void rollDown() {
    int zero = dice[2];
    int three = dice[0];
    int one = dice[3];
    int two = dice[1];
    
    dice[0] = zero;
    dice[1] = one;
    dice[2] = two;
    dice[3] = three;
    return;
}
// 주사위 조작 함수 종료

void roll (int command) {
    int tx = x, ty = y;
    // 명령어에 따라, 주사위를 이동
    // 1: 동쪽, 2: 서쪽, 3: 북쪽, 4: 남쪽
    tx += dx[command];
    ty += dy[command];
    
    // 주사위가 지도 밖으로 나가는 경우, 이후 과정을 수행하지 않고 종료함
    if (!inBoundary(tx, ty)) {
        return;
    }
    
    // 주사위를 명령에 따라 굴림
    x = tx; y = ty;
    switch(command) {
        case 1:
            rollRight();
            break;
        case 2:
            rollLeft();
            break;
        case 3:
            rollDown();
            break;
        case 4:
            rollUp();
            break;
        default:
            return;
    }
    // 굴렸을 때 칸에 쓰인 수가 0이면, 주사위 바닥면의 값이 지도 칸에 복사된다.
    if (grid[x][y] == 0) {
        grid[x][y] = dice[1];
    }
    // 그렇지 않은 경우, 칸에 쓰인 숫자가 주사위 바닥면으로 복사되며, 칸에 쓰인 수는 0이 된다.
    else {
        dice[1] = grid[x][y];
        grid[x][y] = 0;
    }
    cout << dice[0] << '\n';
    return;
}

void init() {
    cin >> n >> m >> x >> y >> k;
    vector<int> tempvec;
    int temp;
    
    // 지도에 쓰여 있는 숫자를 입력 받음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            tempvec.push_back(temp);
        }
        grid.push_back(tempvec);
        tempvec.clear();
    }
    
    // 이동 명령을 입력받음.
    for (int i = 0; i < k; i++) {
        cin >> temp;
        order.push_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 값 입력받음
    init();
    
    // 주사위는 [1, 6, 2, 5, 3, 4] 형식으로 나타내진다.
    // [1과 6은 서로 반대 면에 있고, 2와 5, 3과 4도 마찬가지이다.
    // 1의 왼쪽에는 2, 6의 왼쪽에는 5가 있고, 1의 오른쪽에는 3, 6의 오른쪽에는 4가 있다.
    for (int i = 0; i < k; i++) {
        roll(order[i]);
    }
    return 0;
}

