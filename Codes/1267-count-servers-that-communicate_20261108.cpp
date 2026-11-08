/*
 * @Author: LetMeFly
 * @Date: 2026-11-08 10:46:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-08 10:49:20
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> line(n), row(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    line[i]++;
                    row[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += grid[i][j] && (line[i] > 1 || row[j] > 1);
            }
        }
        return ans;
    }
};
