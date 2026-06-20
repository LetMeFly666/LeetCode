/*
 * @Author: LetMeFly
 * @Date: 2026-06-20 10:09:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-06-20 10:57:16
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    pair<int, int> cal(int a, int ha, int b, int hb) {
        if (ha > hb) {
            int range_height = b - a <= ha - hb ? 
        } else {

        }
    }
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({0, 0});
        sort(restrictions.begin(), restrictions.end());
        int ans = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            auto [range_height, last_height] = cal(restrictions[i - 1][0], restrictions[i - 1][1], restrictions[i][0], restrictions[i][1]);
            ans = max(ans, range_height);
            restrictions[i][1] = min(restrictions[i][1], last_height);
        }
        return ans;
    }
};
