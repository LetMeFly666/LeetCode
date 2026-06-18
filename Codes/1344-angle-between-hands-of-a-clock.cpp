/*
 * @Author: LetMeFly
 * @Date: 2026-06-18 09:58:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-18 10:08:12
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12 + (double)minutes / 60) * 30;
        double m = minutes * 6;
        double diff = abs(h - m);
        return min(diff, 360 - diff);
    }
};
