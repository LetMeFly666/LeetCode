/*
 * @Author: LetMeFly
 * @Date: 2026-07-20 18:04:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-20 18:12:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), size = n * m;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int th = i * m + j;
                int next_th = (th + k) % size;
                ans[next_th / m][next_th % m] = grid[i][j];
            }
        }
        return ans;
    }
};
