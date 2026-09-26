/*
 * @Author: LetMeFly
 * @Date: 2026-06-23 09:49:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-26 22:31:10
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// THIS IS A HALF CODE & CANNOT BE ACCPETED
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
private:
    void debug(ll a[], int l, int r) {
        cout << '[';
        bool first = true;
        for (int i = l; i <= r; i++) {
            if (first) {
                first = false;
            } else {
                cout << ", ";
            }
            cout << a[i];
        }
        puts("]");
    }

    void mulUp(ll old[], ll now[], int l, int r) {
        ll up_cnt = 0;
        for (int i = l; i <= r; i++) {
            now[i] = up_cnt;
            up_cnt = (up_cnt + old[i]) % MOD;
        }
        swap(old, now);
    }

    void mulDown(ll old[], ll now[], int l, int r) {
        ll down_cnt = 0;
        for (int i = r; i >= l; i--) {
            now[i] = down_cnt;
            down_cnt = (down_cnt + old[i]) % MOD;
        }
        swap(old, now);
    }
public:
    int zigZagArrays(int n, int l, int r) {
        ll up[2001];
        ll up2[2001];
        for (int i = l; i <= r; i++) {
            up[i] = 1;
        }

        while (--n) {  // 写到这里发现矩阵快速幂版本错在哪里了！

        }

        ll ans = 0;
        ll cntUp = 0, cntDown = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + up[i]) % MOD;
        }
        return ans * 2 % MOD;
    }
};
