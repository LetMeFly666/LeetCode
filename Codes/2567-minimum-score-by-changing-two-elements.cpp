/*
 * @Author: LetMeFly
 * @Date: 2026-11-19 22:25:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-19 22:27:41
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
            nums[1] - nums[0], min(  // 最小的两个
                nums[n - 1] - nums[n - 2],  // 最大的两个
                nums[n - 2] - nums[1]
            )
        );
    }
};
