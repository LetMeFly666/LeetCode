/*
 * @Author: LetMeFly
 * @Date: 2025-10-11 18:10:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-11 18:38:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#include <algorithm>
#endif

typedef long long ll;
class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> cnt;
        for (int t : power) {
            cnt[t]++;
        }
        vector<pair<int, int>> values(cnt.begin(), cnt.end());
        sort(values.begin(), values.end());
        vector<ll> dp(values.size() + 1);
        for (int i = 0, j = 0; i < values.size(); i++) {
            auto& [value, times] = values[i];
            while (values[j].first < value - 2) {
                j++;
            }
            dp[i + 1] = max(dp[i], dp[j] + (ll) value * times);
        }
        return dp.back();
    }
};
