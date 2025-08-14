/*
 * @Author: LetMeFly
 * @Date: 2025-08-14 10:28:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-14 18:41:02
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};