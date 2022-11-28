/*
 * @Author: LetMeFly
 * @Date: 2022-11-28 20:50:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-28 20:55:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int l = j - 1; l < i; l++) {
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + (prefix[i] - prefix[l]) / (i - l));
                }
            }
        }
        return dp[n][k];
    }
};