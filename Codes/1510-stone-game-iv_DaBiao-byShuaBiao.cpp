/*
 * @Author: LetMeFly
 * @Date: 2026-08-10 11:40:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-10 12:21:13
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

bool win[100001] = {false};
vector<int> losers;
void init() {
    // win[0] = false
    for (int i = 0; i <= 100000; i++) {
        if (win[i]) {
            continue;
        }
        losers.push_back(i);
        for (int x = 1; i + x * x <= 100000; x++) {
            win[i + x * x] = true;
        }
    }
};

int main() {
    init();
    bool first = true;
    for (int t : losers) {
        if (first) {
            cout << "[";
            first = false;
        } else {
            cout << ", ";
        }
        cout << t;
    }
    puts("]");
    return 0;
}
