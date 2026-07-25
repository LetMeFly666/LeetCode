/*
 * @Author: LetMeFly
 * @Date: 2026-07-24 10:22:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-24 10:26:57
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int gcd(int x, int y) {
        while (y) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n * (n + 1), n * n);
    }
};
