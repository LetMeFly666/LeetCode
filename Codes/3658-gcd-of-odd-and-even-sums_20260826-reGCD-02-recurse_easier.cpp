/*
 * @Author: LetMeFly
 * @Date: 2026-08-26 17:33:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-26 17:33:59
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

/*
odd: 1 3 5 ... -> (1+2n-1)*n/2=n^2
even: 2 4 6 ... -> (2+2n)*n/2=n(n+1)
*/
class Solution {
private:
    int myGcd(int x, int y) {
        return y ? myGcd(y, x % y) : x;
    }
public:
    int gcdOfOddEvenSums(int n) {
        return myGcd(n * (n + 1), n * n);
    }
};
