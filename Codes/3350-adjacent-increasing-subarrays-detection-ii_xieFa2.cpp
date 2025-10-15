/*
 * @Author: LetMeFly
 * @Date: 2025-10-15 22:07:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-15 22:20:31
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// THIS IS NOT RIGHT
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int lastCnt = 0, nowCnt = 0, i = 0; i < nums.size(); i++) {
            nowCnt++;
            if (i == nums.size() - 1 || nums[i] >= nums[i + 1]) {  // 递增数组之尾
                ans = max({ans, min(lastCnt, nowCnt), nowCnt / 2});
            }
        }
        return ans;
    }
};