/*
 * @Author: LetMeFly
 * @Date: 2026-11-19 22:25:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-19 22:29:22
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        return min(
            nums[n - 3] - nums[0], min(  // 改最大的两个
                nums[n - 1] - nums[2],     // 改最小的两个
                nums[n - 2] - nums[1]      // 改最小和最大的那两个
            )
        );
    }
};
