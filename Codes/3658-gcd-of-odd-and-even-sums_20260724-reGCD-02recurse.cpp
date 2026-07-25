/*
 * @Author: LetMeFly
 * @Date: 2026-07-24 10:22:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-24 10:25:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n * (n + 1), n * n);
    }
};
