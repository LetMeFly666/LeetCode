/*
 * @Author: LetMeFly
 * @Date: 2026-04-04 14:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-04-04 14:29:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

const int INF = 1e9;
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        array<vector<int>, 3> dp;
        dp.fill(vector<int>(m));
        dp[0][0] = coins[0][0];
        dp[1][0] = dp[2][0] = max(coins[0][0], 0);

        for (int i = 0; i < n; i++) {
            array<vector<int>, 3> nextDP;
            nextDP.fill(vector<int>(m));
            for (int j = 0; j < m; j++) {
                if (!i && !j) {
                    continue;
                }
                for (int th = 0; th < 3; th++) {
                    nextDP[th][j] = coins[i][j] + max(i ? dp[th][j] : -INF, j ? nextDP[th][j - 1] : -INF);
                }
                for (int th = 1; th < 3; th++) {
                    nextDP[th][j] = max(nextDP[th][j], max(i ? dp[th - 1][j] : -INF, j ? nextDP[th - 1][j - 1] : -INF));
                }
            }
            dp = move(nextDP);
        }

        return dp[2][m - 1];
    }
};
