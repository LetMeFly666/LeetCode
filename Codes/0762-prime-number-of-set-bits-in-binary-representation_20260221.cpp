/*
 * @Author: LetMeFly
 * @Date: 2026-02-21 12:13:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-21 12:23:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
class Solution {
private:
    constexpr static int mask = 665772;
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (mask && 1 << __builtin_popcount(i)) {
                ans++;
            }
        }
        return ans;
    }
};