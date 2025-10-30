/*
 * @Author: LetMeFly
 * @Date: 2025-10-21 18:51:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-21 18:51:51
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        k *= 2;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};