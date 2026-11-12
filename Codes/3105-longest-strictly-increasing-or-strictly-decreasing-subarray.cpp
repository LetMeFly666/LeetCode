/*
 * @Author: LetMeFly
 * @Date: 2026-11-12 13:07:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-12 13:08:14
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int ans = 0;
        bool increase = nums[1] > nums[0];
        return ans;
    }
};
