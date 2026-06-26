/*
 * @Author: LetMeFly
 * @Date: 2026-06-23 09:49:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-26 22:27:07
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

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
            up_cnt += old[i];
        }
        swap(old, now);
    }

    void mulDown(ll up[], ll up2[], int l, int r) {
        
    }
public:
    int zigZagArrays(int n, int l, int r) {
        ll up[2001];
        ll up2[2001];
        for (int i = l; i <= r; i++) {
            up[i] = 1;
        }

        

        ll ans = 0;
        ll cntUp = 0, cntDown = 0;
        for (int i = l; i <= r; i++) {
            ans = (ans + up[i]) % MOD;
        }
        return ans * 2 % MOD;
    }
};
