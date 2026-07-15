/*
 * @Author: LetMeFly
 * @Date: 2026-07-15 16:27:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-15 16:29:54
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
odd:  1 3 5 .. 2n-1 -> 2n * n / 2 = n^2
even: 2 4 6 ... 2n  -> (2n+2)*n/2 = n(n+1)
*/
class Solution {
private:
    int gcd(int a, int b) {
        return !b ? a : gcd(b, a % b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n * n, n * (n + 1));
    }
};
