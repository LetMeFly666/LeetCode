/*
 * @Author: LetMeFly
 * @Date: 2026-07-07 11:48:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-07 11:50:28
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll sumAndMultiply(int n) {
        ll cnt = 0, con = 0, pow = 1;
        while (n) {
            ll t = n % 10;
            n /= 10;
            if (!t) {
                continue;
            }
            con += pow * t;
            pow *= 10;
            cnt += t;
        }
        return cnt * con;
    }
};
