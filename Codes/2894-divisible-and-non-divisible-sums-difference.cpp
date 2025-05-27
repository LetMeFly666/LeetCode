/*
 * @Author: LetMeFly
 * @Date: 2025-05-27 21:42:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-27 21:51:58
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (1 + n) * n / 2 - (1 + n / m * m) * (n / m);
    }
};