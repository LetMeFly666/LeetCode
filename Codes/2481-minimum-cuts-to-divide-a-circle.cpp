/*
 * @Author: LetMeFly
 * @Date: 2023-06-17 09:46:05
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-17 09:56:01
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) {
            return 0;
        }
        return n % 2 ? n : n / 2;
    }
};