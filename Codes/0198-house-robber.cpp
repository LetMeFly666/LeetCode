/*
 * @Author: LetMeFly
 * @Date: 2022-04-17 09:38:08
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-17 09:49:48
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTime
// 第一次：dp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(2, 0));  // dp[i][n]前i个店最多偷多少 | n = 0: 第i个店不偷，n = 1：第i个店偷
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = nums[i] + dp[i - 1][0];
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
#else
// 就地滚动
class Solution {
public:
    int rob(vector<int>& nums) {
        int bu = 0, tou = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int NewTou = nums[i] + bu;
            bu = max(bu, tou);
            tou = NewTou;
        }
        return max(bu, tou);
    }
};
#endif