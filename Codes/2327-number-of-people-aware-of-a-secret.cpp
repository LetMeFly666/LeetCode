/*
 * @Author: LetMeFly
 * @Date: 2025-09-09 23:42:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-09 23:52:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> dp(n);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + delay; j < i + forget && j < n; j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }
        ll ans = 0;
        for (int i = 0; i < forget; i++) {
            ans = (ans + dp[n - i - 1]) % MOD;
        }
        return ans;
    }
};