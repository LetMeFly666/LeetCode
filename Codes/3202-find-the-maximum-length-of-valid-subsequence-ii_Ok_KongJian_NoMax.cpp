/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 22:55:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 22:55:40
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        for (int res = 0; res < k; res++) {
            vector<int> dp(k);
            for (int x : nums) {
                x %= k;
                int y = (res - x + k) % k;
                dp[y] = dp[x] + 1;  // 不需要max(dp[y], dp[x] + 1)，因为dp[y]一定拼接自dp[x]，x和y互为一对儿
                ans = max(ans, dp[y]);
            }
        }
        return ans;
    }
};