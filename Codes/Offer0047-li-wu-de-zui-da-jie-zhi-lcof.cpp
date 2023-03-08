/*
 * @Author: LetMeFly
 * @Date: 2023-03-08 17:43:15
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-08 17:46:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if (i == 0 && j != 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                else if (i != 0 && j == 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                else {
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid.back().back();
    }
};