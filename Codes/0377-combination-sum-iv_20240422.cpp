/*
 * @Author: LetMeFly
 * @Date: 2024-04-22 09:59:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-22 10:06:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1);  // 题目说答案保证符合32位整数，但中间运算过程不保证。例如dp[target-1]可能会超int，甚至可能会超long long。使用unsigned让它随便溢出吧，反正会溢出的话一定不是答案
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};