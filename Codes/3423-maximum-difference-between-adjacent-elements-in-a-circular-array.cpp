/*
 * @Author: LetMeFly
 * @Date: 2025-06-12 22:49:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-12 22:52:31
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0] - nums[nums.size() - 1]);
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        }
        return ans;
    }
};