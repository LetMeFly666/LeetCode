/*
 * @Author: LetMeFly
 * @Date: 2026-08-10 11:40:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-10 11:56:05
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

bool win[100001] = {false};
int init = []() {
    // win[0] = false
    for (int i = 1; i <= 100000; i++) {
        for (int x = 1; x * x <= i; x++) {
            if (!win[i - x * x]) {
                win[i] = true;
                break;
            }
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
