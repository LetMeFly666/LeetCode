/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 17:00:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 17:06:07
 * @Description: AC,100.00%,51.97%
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
private:
    ll pow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        return pow(5, (n + 1) / 2) * pow(4, n / 2) % MOD;
    }
};