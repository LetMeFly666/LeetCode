/*
 * @Author: LetMeFly
 * @Date: 2024-03-01 19:58:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-01 20:03:16
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(nums.size() + 1);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 - 2 >= 0 && dp[i + 1 - 2] && nums[i] == nums[i - 1]) {
                dp[i + 1] = true;
            }
            if (i + 1 - 3 >= 0 && dp[i + 1 - 3] && ((nums[i] == nums[i - 1] && nums[i] == nums[i - 2] || nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))) {
                dp[i + 1] = true;
            }
        }
        return dp.back();
    }
};