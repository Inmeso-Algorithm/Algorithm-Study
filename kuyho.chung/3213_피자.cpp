#include <iostream>
#include <algorithm>
using namespace std;

int N;
int total_pizza = 0;
int pizza[3] = {0, };  // 1/4, 1/2, 3/4 each

int main() {
    
    ios::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        if (a == '1') {
            if (c == '4')
                pizza[0]++;
            else
                pizza[1]++;
        }
        else
            pizza[2]++;
    }
    
    //먼저 1/2조각을 먹는 사람의 수를 센다. pizza[1]에는 0 또는 1의 값이 남을 것.
    total_pizza = pizza[1] / 2;
    pizza[1] -= total_pizza * 2;
    //cout << pizza[1] << endl;
    
    // 1/4조각을 먹는 사람과 3/4조각을 먹는 사람을 짝지어 본다.
    int pair = min(pizza[0], pizza[2]);
    total_pizza += pair;
    pizza[0] -= pair;
    pizza[2] -= pair;
    
    // 1/4조각을 먹는 사람과 1/2조각을 먹는 사람을 짝지어 본다.
    // pizza[1]의 최댓값은 1이므로, 1/2조각과 1/4조각 한사람이 짝지어지거나 짝지어지지 않는다.
    pair = min(pizza[0], pizza[1]);
    total_pizza += pair;
    pizza[0] -= pair;
    pizza[1] -= pair;
    
    // 1/4조각만으로 피자가 몇 판이 필요한지 확인한다.
    pair = pizza[0] / 4;
    total_pizza += pair;
    pizza[0] -= pair * 4;
    
    if (pizza[0] != 0) {
        total_pizza++;
        pizza[0] = 0;
    }
    
    //pizza[1]과 pizza[2]는 각각 0 또는 1의 값을 가진다.
    total_pizza += pizza[1] + pizza[2];
    cout << total_pizza;
    
    return 0;
}