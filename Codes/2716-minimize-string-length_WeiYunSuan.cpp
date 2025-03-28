/*
 * @Author: LetMeFly
 * @Date: 2025-03-28 13:28:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-28 13:29:13
 * @Description: AC,100.00%,82.68%
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimizedStringLength(string s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return __builtin_popcount(mask);
    }
};