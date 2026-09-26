/*
 * @Author: LetMeFly
 * @Date: 2026-08-10 11:40:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-10 12:02:16
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

bool win[100001] = {false};
int init = []() {
    // win[0] = false
    for (int i = 0; i <= 100000; i++) {
        if (win[i]) {
            continue;
        }
        for (int x = 1; i + x * x <= 100000; x++) {
            win[i + x * x] = true;
        }
    }
    return 0;
}();

class Solution {
public:
    bool winnerSquareGame(int n) {
        return win[n];
    }
};
