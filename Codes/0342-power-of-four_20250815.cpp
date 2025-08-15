/*
 * @Author: LetMeFly
 * @Date: 2025-08-15 18:29:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-15 18:49:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};