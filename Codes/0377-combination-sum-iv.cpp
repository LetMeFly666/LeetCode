/*
 * @Author: LetMeFly
 * @Date: 2022-10-10 20:13:20
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-10 20:16:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && ((long long)dp[i] + dp[i - num] <= INT_MAX)) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};