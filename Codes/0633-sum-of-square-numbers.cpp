/*
 * @Author: LetMeFly
 * @Date: 2024-11-04 19:43:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-04 19:44:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = sqrt(c); a >= 0; a--) {
            int b = sqrt(c - a * a);
            if (b * b + a * a == c) {
                return true;
            }
        }
        return false;
    }
};