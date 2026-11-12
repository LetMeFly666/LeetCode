/*
 * @Author: LetMeFly
 * @Date: 2026-11-12 13:07:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-12 13:15:11
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int cntAsc = 1, cntDesc = 1;
        size_t n = nums.size();
        for (size_t i = 1; i <= n; i++) {
            if (i == n || nums[i] <= nums[i - 1]) {
                ans = max(ans, cntAsc);
                cntAsc = 0;
            }
            cntAsc++;
            if (i == n || nums[i] >= nums[i - 1]) {
                ans = max(ans, cntDesc);
                cntDesc = 0;
            }
            cntDesc++;
        }
        return ans;
    }
};
