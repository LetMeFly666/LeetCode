/*
 * @Author: LetMeFly
 * @Date: 2025-01-11 22:22:22(about)
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 23:55:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int min3(int a, int b, int c) {
        return min(min(a, b), c);
    }
public:
    int generateKey(int num1, int num2, int num3) {
        return 1000 * min3(num1 / 1000, num2 / 1000, num3 / 1000) + 
               100 * min3(num1 / 100 % 10, num2 / 100 % 10, num3 / 100 % 10) + 
               10 * min3(num1 / 10 % 10, num2 / 10 % 10, num3 / 10 % 10) +
               min3(num1 % 10, num2 % 10, num3 % 10);
    }
};