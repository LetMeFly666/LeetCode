/*
 * @Author: LetMeFly
 * @Date: 2026-04-18 18:52:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-18 18:53:10
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int reverse(int n) {
        int ans = 0;
        while (n) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};