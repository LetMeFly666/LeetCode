/*
 * @Author: LetMeFly
 * @Date: 2026-06-18 09:58:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-18 10:02:14
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int diff = abs(hour * 5 - minutes);
        diff = min(diff, 60 - diff);
        return 6 * diff;  // 这次肯定还是WA，但是先fix一个bug再说，一个格子是6°不是3°
    }
};
