/*
 * @Author: LetMeFly
 * @Date: 2022-12-22 15:19:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-22 15:30:24
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int gcd[n][n];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                gcd[i][j] = __gcd(nums[i], nums[j]);
        int mask = 1 << n;
        vector<int> dp(mask, 0);
        for (int state = 0; state < mask; state++) {
            int one = __builtin_popcount(state);
            if (one % 2)
                continue;
            for (int i = 0; i < n; i++) {
                if (state & (1 << i)) {
                    for (int j = i + 1; j < n; j++) {
                        if (state & (1 << j)) {
                            dp[state] = max(dp[state], dp[state - (1 << i) - (1 << j)] + one / 2 * gcd[i][j]);
                        }
                    }
                }
            }
        }
        return dp[mask - 1];
    }
};