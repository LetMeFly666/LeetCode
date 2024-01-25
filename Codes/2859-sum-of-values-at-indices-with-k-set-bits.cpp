/*
 * @Author: LetMeFly
 * @Date: 2024-01-25 08:57:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-25 08:58:52
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int t : nums) {
            if (__builtin_popcount(t) == k) {
                ans += t;
            }
        }
        return ans;
    }
};