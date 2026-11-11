/*
 * @Author: LetMeFly
 * @Date: 2026-11-11 22:07:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-11 22:20:04
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return min((ll)costBoth * max(need1, need2), (min(
            (ll)costBoth * min(need1, need2) + (need1 < need2 ? (ll)cost2 * (need2 - need1) : (ll)cost1 * (need1 - need2)),
            (ll)cost1 * need1 + (ll)cost2 * need2
        )));
    }
};
