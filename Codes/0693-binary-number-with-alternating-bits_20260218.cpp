/*
 * @Author: LetMeFly
 * @Date: 2026-02-18 14:51:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-18 14:54:37
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = (n >> 1) ^ n;
        return (x + 1) & x == 0;
    }
};