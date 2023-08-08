/*
 * @Author: LetMeFly
 * @Date: 2023-08-08 07:55:01
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-08 07:57:07
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = abs(nums[0]), m = nums[0], M = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            M = max(nums[i], M + nums[i]);
            m = min(nums[i], m + nums[i]);
            ans = max(ans, max(M, -m));
        }
        return ans;
    }
};