/*
 * @Author: LetMeFly
 * @Date: 2025-09-09 23:42:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-11 10:34:24
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> diff(n + 1);
        diff[1] = 1;
        diff[2] = -1;
        int now = 0;
        for (int i = 1; i <= n; i++) {
            now += diff[i];
            if (i + delay <= n) {
                diff[i + delay] = (diff[i + delay] + now) % MOD;
            }
            if (i + forget <= n) {
                diff[i + forget] = (diff[i + forget] + MOD - now) % MOD;
            }
        }
        return now;
    }
};