/*
 * @Author: LetMeFly
 * @Date: 2026-01-25 10:32:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-25 10:33:04
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 100000;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};