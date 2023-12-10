/*
 * @Author: LetMeFly
 * @Date: 2023-12-10 20:22:29
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-10 20:23:36
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int climbStairs(int n) {
        int _0 = 1, _1 = 1;
        for (int i = 2; i <= n; i++) {
            int _2 = _0 + _1;
            _0 = _1, _1 = _2;
        }
        return _1;
    }
};