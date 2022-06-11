/*
 * @Author: LetMeFly
 * @Date: 2022-06-11 10:42:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-11 10:43:42
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int a = 1, b = 2;
        int c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b, b = c;
        }
        return c;
    }
};