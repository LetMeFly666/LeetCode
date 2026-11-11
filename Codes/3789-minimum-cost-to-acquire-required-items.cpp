/*
 * @Author: LetMeFly
 * @Date: 2026-11-11 22:07:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-11 22:08:40
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (costBoth <= cost1 + cost2) {
            return max(need1, need2);
        }
        
    }
};
