/*
 * @Author: LetMeFly
 * @Date: 2025-10-11 18:10:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-11 18:18:57
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
// 感觉会WA
class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        vector<ll> dp(4);
        for (int i = 0; i < min(n, 3); i++) {
            dp[i + 1] = power[i];
        }
        for (int i = 3; i < n; i++) {
            ll thisVal = max(dp[0] + power[i], dp[3]);
            dp[0] = dp[1], dp[1] = dp[2], dp[2] = dp[3], dp[3] = thisVal;
        }
        return max(dp[1], max(dp[2], dp[3]));
    }
};