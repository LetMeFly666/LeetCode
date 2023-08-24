/*
 * @Author: LetMeFly
 * @Date: 2023-08-24 09:05:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-24 09:12:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += grid[i][j], col[j] += grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += grid[i][j] * (row[i] > 1 || col[j] > 1);
            }
        }
        return ans;
    }
};