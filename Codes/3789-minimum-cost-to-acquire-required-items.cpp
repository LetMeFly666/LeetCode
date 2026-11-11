/*
 * @Author: LetMeFly
 * @Date: 2026-11-11 22:07:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-11 22:12:58
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth <= cost1 + cost2) {
            return (ll)costBoth * max(need1, need2);
        }
        if (cost1 < cost2) {
            swap(cost1, cost2);
            swap(need1, need2);
        }
        if (cost2 >= costBoth && need2 > need1) {
            return (ll)costBoth * need2;
        }
        
    }
};
