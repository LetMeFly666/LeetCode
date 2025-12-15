/*
 * @Author: LetMeFly
 * @Date: 2025-12-15 13:32:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-15 18:52:23
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll getDescentPeriods(vector<int>& prices) {
        ll ans = 0, cnt = 0;
        int last = 0;
        for (int t : prices) {
            if (t != last - 1) {
                ans += cnt * (cnt + 1) / 2;
                // printf("t = %d, cnt = %lld\n", t, cnt);
                cnt = 0;
            }
            last = t;
            cnt++;
        }
        return ans + cnt * (cnt + 1) / 2;
    }
};