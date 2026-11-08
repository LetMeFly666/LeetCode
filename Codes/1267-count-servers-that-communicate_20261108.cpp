/*
 * @Author: LetMeFly
 * @Date: 2026-11-08 10:46:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-08 10:48:19
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<bool> line(n), row(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    line[i] = true;
                    row[j] = true;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += grid[i][j] && (line[i] || )
            }
        }
    }
};
