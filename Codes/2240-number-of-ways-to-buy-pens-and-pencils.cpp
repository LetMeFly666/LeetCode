/*
 * @Author: LetMeFly
 * @Date: 2023-09-01 09:22:57
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-01 09:25:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans = 0;
        if (cost1 > cost2) {  // let cost1 <= cost2
            swap(cost1, cost2);
        }
        int M2 = total / cost2;  // max2
        for (int i = 0; i <= M2; i++) {
            ans += (total - cost2 * i) / cost1 + 1;
        }
        return ans;
    }
};