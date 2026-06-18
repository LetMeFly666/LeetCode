/*
 * @Author: LetMeFly
 * @Date: 2026-06-18 09:58:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-18 09:59:33
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int diff = abs(hour * 5 - minutes);
        diff = min(diff, 60 - diff);
        return 3 * diff;
    }
};
