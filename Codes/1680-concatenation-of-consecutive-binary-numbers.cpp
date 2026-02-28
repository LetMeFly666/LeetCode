/*
 * @Author: LetMeFly
 * @Date: 2026-02-28 10:10:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-28 10:14:23
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int concatenatedBinary(int n) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ((ans << bit_width(i)) + i) % MOD;
        }
        return ans;
    }
};
