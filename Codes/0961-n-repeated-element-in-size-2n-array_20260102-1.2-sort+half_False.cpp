/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 13:06:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 13:12:58
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0] == nums[1] ? nums[0] : nums.back();
    }
};