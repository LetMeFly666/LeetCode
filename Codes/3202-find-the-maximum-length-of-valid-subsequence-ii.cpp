/*
 * @Author: LetMeFly
 * @Date: 2025-07-18 22:33:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-20 19:32:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k));
        int ans = 0;
        for (int x : nums) {
            x %= k;
            for (int y = 0; y < k; y++) {
                dp[y][x] = dp[x][y] + 1;
                ans = max(ans, dp[y][x]);
            }
        }
        return ans;
    }
};