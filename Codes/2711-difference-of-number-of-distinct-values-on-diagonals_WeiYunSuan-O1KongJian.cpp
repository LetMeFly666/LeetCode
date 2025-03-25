/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 21:06:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:12:57
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;


class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < m ? 0 : k - m + 1, j = k < m ? k : 0;
            ll se = 0;
            int d = 1;
            for (; i + d < n && j + d < m; d++) {
                ans[i + d][j + d] = __builtin_popcountll(se);
                se |= 1LL << ans[i + d][j + d];
            }
            se = 0;
            for (d--; d >= 0; d--) {
                ans[i + d][j + d] = abs(ans[i + d][j + d] - __builtin_popcountll(se));
                se |= 1LL << ans[i + d][j + d];
            }
        }
        return ans;
    }
};