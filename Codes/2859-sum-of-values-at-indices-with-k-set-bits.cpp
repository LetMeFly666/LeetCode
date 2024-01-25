/*
 * @Author: LetMeFly
 * @Date: 2024-01-25 08:57:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-01-25 09:00:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(i) == k) {
                ans += nums[i];
            }
        }
        return ans;
    }
};