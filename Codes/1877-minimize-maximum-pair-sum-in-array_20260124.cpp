/*
 * @Author: LetMeFly
 * @Date: 2026-01-24 09:29:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-24 09:30:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() / 2; i++) {
            ans = max(ans, nums[i] + nums[nums.size() - i - 1]);
        }
        return ans;
    }
};