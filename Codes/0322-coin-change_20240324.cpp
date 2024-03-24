/*
 * @Author: LetMeFly
 * @Date: 2024-03-24 11:57:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-24 12:00:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e5);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int t : coins) {
                if (i - t >= 0) {
                    dp[i] = min(dp[i], dp[i - t] + 1);
                }
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};