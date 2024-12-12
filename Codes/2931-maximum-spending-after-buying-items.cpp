/*
 * @Author: LetMeFly
 * @Date: 2024-12-12 14:30:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-12 14:36:57
 * AC,100.00%,95.40%
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    ll maxSpending(vector<vector<int>>& values) {
        vector<int> loc(values.size(), values[0].size() - 1);
        ll ans = 0;
        int cnt = values.size() * values[0].size();
        ll th = 1;
        while (cnt--) {
            int m = 1e7, mLoc;
            for (int i = 0; i < values.size(); i++) {
                if (loc[i] >= 0 && values[i][loc[i]] < m) {
                    m = values[i][loc[i]];
                    mLoc = i;
                }
            }
            ans += values[mLoc][loc[mLoc]] * th;
            th++, loc[mLoc]--;
        }
        return ans;
    }
};