/*
 * @Author: LetMeFly
 * @Date: 2025-05-06 21:30:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-06 21:32:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};