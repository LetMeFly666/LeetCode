/*
 * @Author: LetMeFly
 * @Date: 2024-03-15 18:02:51
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-03-15 18:07:55
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1));
        for (vector<int>& price : prices) {
            dp[price[0]][price[1]] = price[2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= i / 2; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
                }
                for (int k = 1; k <= j / 2; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
                }
            }
        }
        return dp[m][n];
    }
};