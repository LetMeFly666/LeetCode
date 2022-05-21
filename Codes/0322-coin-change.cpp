/*
 * @Author: LetMeFly
 * @Date: 2022-04-15 10:23:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-15 10:28:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int coinChange(vector<int>& coins_, int amount) {
        vector<int> dp(amount + 1, 1e8);
        dp[0] = 0;
        vector<int> coins;
        for (int& coin : coins_)
            if (coin <= amount)
                coins.push_back(coin);
        // dp[i]: 凑够i元至少需要多少个硬币
        for (int& coin : coins)
                dp[coin] = 1;
        for (int i = 0; i < amount; i++) {
            for (int& coin : coins) {
                if (i + coin <= amount)
                    dp[i + coin] = min(dp[i + coin], dp[i] + 1);
            }
        }
        return dp[amount] > 1e7 ? -1 : dp[amount];
    }
};