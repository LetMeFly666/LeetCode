/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 19:44:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 19:51:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < m ? 0 : k - m + 1, j = k < m ? k : 0;
            unordered_set<int> se;
            int d = 0;
            for (; i + d < n && j + d < m; d++) {
                ans[i + d][j + d] = se.size();
                se.insert(ans[i + d][j + d]);
            }
            se.clear();
            for (d--; )
        }
        return ans;
    }
};