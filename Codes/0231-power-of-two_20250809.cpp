/*
 * @Author: LetMeFly
 * @Date: 2025-08-09 22:23:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-09 22:33:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return n > 0 && n & (n - 1) == 0;  // 不可
        // return n > 0 && (n & (n - 1) == 0);  // 不可
        return n > 0 && (n & (n - 1)) == 0;
    }
};