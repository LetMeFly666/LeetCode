/*
 * @Author: LetMeFly
 * @Date: 2026-09-26 09:46:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-26 09:50:11
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x ;
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n * (n + 1), n * n);
    }
};
