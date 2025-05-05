/*
 * @Author: LetMeFly
 * @Date: 2025-05-05 21:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-05 22:23:11
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry  // Error
const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
            if (i >= 2) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
            if (i >= 3) {
                dp[i] = (dp[i] + dp[i - 3]) % MOD;
                dp[i] = (dp[i] + dp[i - 3]) % MOD;
            }
        }
        return dp.back();
    }
};
#else  // FirstTry
// SecondTry
const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 1] * 2) % MOD + dp[i - 3]) % MOD;
        }
        return dp.back();
    }
};
#endif  // FirstTry