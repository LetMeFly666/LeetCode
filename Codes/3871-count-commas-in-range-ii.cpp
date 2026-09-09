/*
 * @Author: LetMeFly
 * @Date: 2026-09-09 13:32:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-09 13:34:36
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    long long countCommas(long long n) {
        ll now = 1000;
        ll ans = 0;
        int num = 1;
        while (now <= n) {
            ans += num * (min(now * 1000 - 1, n) - now);
            num++;
            now *= 1000;
        }
        return ans;
    }
};
