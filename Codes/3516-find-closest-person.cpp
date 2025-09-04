/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:35:13
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff = abs(x - z) - abs(y - z);
        return diff ? diff > 0 ? 2 : 1 : 0
    }
};