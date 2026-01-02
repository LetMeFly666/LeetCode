/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 13:06:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 13:18:02
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        return nums[mid] == nums[mid + 1] ? nums[mid] : nums[mid - 1];
    }
};