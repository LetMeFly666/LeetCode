/*
 * @Author: LetMeFly
 * @Date: 2026-02-16 15:23:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-16 15:26:10
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int reverseBits(int n) {
        unsigned ans = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            if (n & 1) {
                ans |= 1 << (31 - i);
            }
        }
        return ans;
    }
};