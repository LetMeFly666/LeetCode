/*
 * @Author: LetMeFly
 * @Date: 2022-09-29 12:44:11
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-29 12:45:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        while (n != 1) {
            if (n % 4) {
                return false;
            }
            n /= 4;
        }
        return true;
    }
};