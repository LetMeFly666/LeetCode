/*
 * @Author: LetMeFly
 * @Date: 2024-08-15 23:00:56
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-15 23:55:59
 * @Description: 这是开会的时候启的每日一题，所以看起来写了很久
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = grid[0][1] - grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int original = grid[i][j];
                if (i > 0) {
                    grid[i][j] = min(grid[i][j], grid[i - 1][j]);
                    ans = max(ans, original - grid[i - 1][j]);
                }
                if (j > 0) {
                    grid[i][j] = min(grid[i][j], grid[i][j - 1]);
                    ans = max(ans, original - grid[i][j - 1]);
                }
            }
        }
        return ans;
    }
};