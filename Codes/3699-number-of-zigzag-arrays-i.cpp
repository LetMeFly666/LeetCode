/*
 * @Author: LetMeFly
 * @Date: 2026-06-23 09:49:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-23 10:00:26
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        ll up[2001], down[2001];
        ll up2[2001], down2[2001];
        for (int i = l; i <= r; i++) {
            up[i] = down[i] = 1;
        }

        while (--n) {
            ll up_cnt = 0;
            for (int i = l; i <= r; i++) {
                up2[i] = up_cnt;
                up_cnt = (up_cnt + down[i]) % MOD;
            }

            ll down_cnt = 0;
            for (int i = r; i >= l; i--) {
                down2[i] = down_cnt;
                down_cnt = (down_cnt + up[i]) % MOD;
            }

            swap(up, up2);
            swap(down, down2);
        }

        ll ans = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }
        return ans;
    }
};
