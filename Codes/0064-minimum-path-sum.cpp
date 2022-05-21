/*
 * @Author: LetMeFly
 * @Date: 2022-04-20 15:02:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-20 15:05:09
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int add = 1e8;
                if (i) add = min(add, grid[i - 1][j]);
                if (j) add = min(add, grid[i][j - 1]);
                grid[i][j] += add == 1e8 ? 0 : add;
            }
        }
        return grid[n - 1][m - 1];
    }
};