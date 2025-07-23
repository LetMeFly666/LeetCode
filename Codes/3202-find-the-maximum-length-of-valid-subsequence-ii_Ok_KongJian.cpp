/*
 * @Author: LetMeFly
 * @Date: 2025-07-21 22:44:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-21 22:46:43
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
                dp[y] = max(dp[y], dp[x] + 1);
                ans = max(ans, dp[y]);
            }
        }
        return ans;
    }
};