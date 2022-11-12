/*
 * @Author: LetMeFly
 * @Date: 2022-11-12 08:33:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-12 08:53:04
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // Error
typedef long long ll;
const static int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1)
            return 1;
        vector<ll> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] * 2) % MOD;
        }
        return dp.back();
    }
};
#else  // FirstTry
// SecondTry  // 原理见：https://leetcode.cn/problems/domino-and-tromino-tiling/solutions/1962465/duo-mi-nuo-he-tuo-mi-nuo-ping-pu-by-leet-7n0j/
typedef long long ll;
const static ll MOD = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }
        return dp.back().back();
    }
};
#endif  // FirstTry