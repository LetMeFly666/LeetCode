/*
 * @Author: LetMeFly
 * @Date: 2026-06-01 22:06:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-01 22:07:10
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.begin(), cost.end(), greater<>());
        for (int i = 0, n = cost.size(), cnt = 0; i < n; i++) {
            if (cnt == 2) {
                cnt = 0;
            } else {
                ans += cost[i];
                cnt++;
            }
        }
        return ans;
    }
};
