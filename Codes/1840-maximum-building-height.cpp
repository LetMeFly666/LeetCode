/*
 * @Author: LetMeFly
 * @Date: 2026-06-20 10:09:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-20 10:17:47
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int cal(int a, int ha, int b, int hb) {
        if (ha > hb) {
            swap(ha, hb);
            swap(a, b);
        }
        if (hb - ha <= b - a) {
            return ha + b - a;
        }
        return hb + (b - a - (hb - ha) - 1) / 2;
    }
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({0, 0});
        sort(restrictions.begin(), restrictions.end());
        int ans = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            ans = max(ans, cal(restrictions[i - 1][0], restrictions[i - 1][1], restrictions[i][0], restrictions[i][1]));
        }
        return ans;
    }
};
