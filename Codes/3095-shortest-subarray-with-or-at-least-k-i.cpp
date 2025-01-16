/*
 * @Author: LetMeFly
 * @Date: 2025-01-16 12:22:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-16 12:25:45
 */

// 开始读题
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = 100;
        for (int l = 0; l < nums.size(); l++) {
            int val = nums[l];
            for (int r = l; r < nums.size(); r++) {
                val |= nums[r];
                if (val >= k) {
                    ans = min(ans, r - l + 1);
                    break;
                }
            }
        }
        return ans == 100 ? -1 : ans;
    }
};