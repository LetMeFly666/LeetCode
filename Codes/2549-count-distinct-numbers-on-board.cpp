/*
 * @Author: LetMeFly
 * @Date: 2024-03-23 11:15:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-23 11:15:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1 ? 1 : n - 1;
    }
};