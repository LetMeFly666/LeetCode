/*
 * @Author: LetMeFly
 * @Date: 2025-09-09 23:42:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-11 10:49:54
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
        ll now = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            now = (now + diff[i]) % MOD;
            if (i + forget > n) {
                ans = (ans + now) % MOD;
            }
            if (i + delay <= n) {
                diff[i + delay] = (diff[i + delay] + now) % MOD;
            }
            if (i + forget <= n) {
                diff[i + forget] = (diff[i + forget] + MOD - now) % MOD;
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
6 2 4

5
*/
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        Solution sol;
        cout << sol.peopleAwareOfSecret(a, b, c) << endl;
    }
    return 0;
}
#endif