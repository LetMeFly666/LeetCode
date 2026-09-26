/*
 * @Author: LetMeFly
 * @Date: 2026-09-26 09:46:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-26 09:52:17
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int myGCD(int x, int y) {
        while (y) {
            // x, y = y, x % y
            int t = y;
            y = x % y;
            x = t;
        }
        return x;
    }
public:
    int gcdOfOddEvenSums(int n) {
        return myGCD(n * (n + 1), n * n);
    }
};
