/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:30:45
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximum69Number (int num) {
        int first6loc = -1;
        for (int n = num, loc = 0; n; n /= 10, loc++) {
            if (n % 10 == 6) {
                first6loc = loc;
            }
        }
        if (first6loc == -1) {
            return num;
        }
        return num + 3 * pow(10, first6loc);
    }
};