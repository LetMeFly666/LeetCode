/*
 * @Author: LetMeFly
 * @Date: 2022-04-18 11:39:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-18 11:41:50
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};