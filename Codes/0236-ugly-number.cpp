/*
 * @Author: LetMeFly
 * @Date: 2022-09-13 08:35:44
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-09-13 08:36:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return false;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else if (n % 3 == 0)
                n /= 3;
            else if (n % 5 == 0)
                n /= 5;
            else
                return false;
        }
        return true;
    }
};