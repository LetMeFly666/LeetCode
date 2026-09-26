/*
 * @Author: LetMeFly
 * @Date: 2026-03-18 22:17:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-18 22:19:52
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j) {
                    grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                } else if (i) {
                    grid[i][j] += grid[i - 1][j];
                } else if (j) {
                    grid[i][j] += grid[i][j - 1];
                }
                ans += grid[i][j] <= k;
            }
        }
        return ans;
    }
};