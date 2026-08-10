/*
 * @Author: LetMeFly
 * @Date: 2026-08-10 11:40:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-10 11:45:23
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// char纯属为了省点空间
char win[100001] = {0};  // 0: 未更新 | 1: win | 2: false

class Solution {
public:
    bool winnerSquareGame(int n) {
        if (win[n]) {
            return win[n] == 1;
        }
        if (!n) {
            win[n] = 2;
            return false;
        }
        for (int x = 1; x * x <= n; x++) {
            if (!winnerSquareGame(n - x)) {
                win[n] = 1;
                return true;
            }
        }
        win[n] = 2;
        return false;
    }
};
