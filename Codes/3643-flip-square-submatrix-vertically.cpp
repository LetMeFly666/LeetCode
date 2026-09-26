/*
 * @Author: LetMeFly
 * @Date: 2026-03-21 14:05:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-21 14:07:46
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> &reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - i - 1][y + j]);
            }
        }
        return grid;
    }
};