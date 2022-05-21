/*
 * @Author: LetMeFly
 * @Date: 2022-04-05 15:40:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-05 15:46:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

bool prime[21] = {
    0,
    0, 1, 1, 0, 1,
    0, 1, 0, 0, 0,
    1, 0, 1, 0, 0,
    0, 1, 0, 1, 0,
};

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            ans += prime[__builtin_popcount(i)];
        }
        return ans;
    }
};