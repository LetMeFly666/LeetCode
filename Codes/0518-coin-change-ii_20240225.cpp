/*
 * @Author: LetMeFly
 * @Date: 2024-03-25 10:20:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-25 10:21:34
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp.back();
    }
};