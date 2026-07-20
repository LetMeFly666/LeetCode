/*
 * @Author: LetMeFly
 * @Date: 2026-07-20 18:04:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-20 18:07:34
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), all = n * m;
        int a[all], b[all];
        for (int i = 0, th = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[th++] = grid[i][j];
            }
        }
        
        for (int i = 0; i < all; i++) {
            b[(i + k) % all] = a[i];
        }
        for (int i = 0, th = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = b[th++];
            }
        }
        return grid;
    }
};
