/*
 * @Author: LetMeFly
 * @Date: 2022-04-07 20:21:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-07 20:25:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
// n >>= 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
#else
// __builtin_popcount
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
#endif