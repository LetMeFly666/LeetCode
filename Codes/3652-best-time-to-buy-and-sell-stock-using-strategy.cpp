/*
 * @Author: LetMeFly
 * @Date: 2025-12-18 13:17:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-18 18:42:50
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            ans += strategy[i] * prices[i];
        }

        ll now = ans;
        for (int i = 0; i < k / 2; i++) {
            now += (0 - strategy[i]) * prices[i];
        }
        for (int i = k / 2; i < k; i++) {
            now += (1 - strategy[i]) * prices[i];
        }
        ans = max(ans, now);

        for (int i = 1; i + k <= n; i++) {
            // i-1: 0->original
            // i+k/2-1: 1->0
            // i+k-1: original->1
            now += (strategy[i - 1] - 0) * prices[i - 1] + (0 - 1) * prices[i + k/2 - 1] + (1 - strategy[i + k - 1]) * prices[i + k - 1];
            ans = max(ans, now);
        }
        return ans;
    }
};