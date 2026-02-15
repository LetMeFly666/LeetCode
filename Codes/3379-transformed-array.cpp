/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 18:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 18:11:29
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0, n = nums.size(); i < n; i++) {
            ans[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return ans;
    }
};