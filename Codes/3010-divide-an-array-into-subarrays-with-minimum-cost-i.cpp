/*
 * @Author: LetMeFly
 * @Date: 2026-02-01 09:49:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-01 09:51:34
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};