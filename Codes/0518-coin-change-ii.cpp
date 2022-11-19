/*
 * @Author: LetMeFly
 * @Date: 2022-11-19 14:41:12
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-19 14:42:19
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int& t : coins) {
            for (int i = t; i <= amount; i++)
                dp[i] += dp[i - t];
        }
        return dp.back();
    }
};