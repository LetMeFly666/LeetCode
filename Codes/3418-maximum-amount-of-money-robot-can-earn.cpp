/*
 * @Author: LetMeFly
 * @Date: 2026-04-02 23:07:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-03 08:24:53
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        array<vector<vector<int>>, 3> dp;
        dp.fill(vector<vector<int>>(n, vector<int>(m)));
        dp[0][0][0] = coins[0][0];
        dp[1][0][0] = dp[2][0][0] = max(coins[0][0], 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) {
                    continue;
                }
                for (int th = 0; th < 3; th++) {
                    dp[th][i][j] = coins[i][j] + max(i ? dp[th][i - 1][j] : -1000, j ? dp[th][i][j - 1] : -1000);
                    // printf("dp[%d][%d][%d] = %d\n", th, i, j, dp[th][i][j]);
                }
                for (int th = 1; th < 3; th++) {
                    // int a = dp[th][i][j], b = max(i ? dp[th - 1][i - 1][j] : -1000, j ? dp[th - 1][i][j - 1] : -1000);
                    // if (b > a) {
                    //     printf("dp[%d][%d][%d]: %d -> ", th, i, j, a);
                    //     if (i && dp[th - 1][i - 1][j] > (j ? dp[th - 1][i][j - 1] : 0)) {
                    //         printf
                    //     } else {
                    //         printf
                    //     }
                    // }
                    dp[th][i][j] = max(dp[th][i][j], max(i ? dp[th - 1][i - 1][j] : -1000, j ? dp[th - 1][i][j - 1] : -1000));
                }
            }
        }

        return dp[2][n - 1][m - 1];
    }
};
