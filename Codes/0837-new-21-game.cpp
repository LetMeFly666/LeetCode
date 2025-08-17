/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 19:38:09
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k + maxPts);
        double s = 0;
        for (int i = k; i < k + maxPts; i++) {
            dp[i] = i <= n;
            s += dp[i];
        }
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = s / maxPts;
            s = s - dp[i + maxPts] + dp[i];
        }
        return dp[0];
    }
};