/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:34:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximum69Number (int num) {
        int base = 0;
        for (int n = num, loc = 0, nowPow = 1; n; n /= 10, loc++, nowPow *= 10) {
            if (n % 10 == 6) {
                base = nowPow;
            }
        }
        return num + base * 3;
    }
};