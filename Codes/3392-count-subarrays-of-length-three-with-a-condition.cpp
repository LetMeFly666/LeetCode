/*
 * @Author: LetMeFly
 * @Date: 2025-04-27 23:47:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-27 23:48:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 2; i < nums.size(); i++) {
            ans += (nums[i] + nums[i - 2]) * 2 == nums[i - 1];
        }
        return ans;
    }
};