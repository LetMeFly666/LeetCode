/*
 * @Author: LetMeFly
 * @Date: 2026-11-26 07:52:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-26 07:55:55
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canAliceWin(int n) {
        bool state = false;
        int should = 10;
        while (true) {
            if (n < should) {
                return state;
            }
            n -= should--;
            state = !state;
        }
    }
};
