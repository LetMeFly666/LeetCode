/*
 * @Author: LetMeFly
 * @Date: 2026-02-19 17:38:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-19 17:39:31
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2) {
            low--;
        }
        if (high % 2) {
            high++;
        }
        return (high - low) >> 1;
    }
};