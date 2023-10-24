/*
 * @Author: LetMeFly
 * @Date: 2023-10-24 14:29:37
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-10-24 14:32:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, 0));
        for (int j = 1; j <= k; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int _k = 1; k <= min(k, j); _k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
        return dp[k][target];
    }
};