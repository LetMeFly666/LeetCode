/*
 * @Author: LetMeFly
 * @Date: 2026-11-24 12:56:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-24 13:02:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int myGcd(int x, int y) {
        while (x % y) {
            // x, y = y, x % y
            int tmp = x;
            x = y;
            y = tmp % y;
        }
        return y;
    }
public:
    int gcdOfOddEvenSums(int n) {
        // 1 3 5 7 -> (1+2n-1)*n/2 = n*n
        // 2 4 6 8 -> n*n + n
        return myGcd(n * n + n, n * n);
    }
};
