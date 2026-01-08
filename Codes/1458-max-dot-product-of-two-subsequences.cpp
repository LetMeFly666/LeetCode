/*
 * @Author: LetMeFly
 * @Date: 2026-01-08 09:21:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-08 09:23:30
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                if (j) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
                if (i && j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i] * nums2[j]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};