/*
 * @Author: LetMeFly
 * @Date: 2024-11-15 09:35:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-15 09:39:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int forLine(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                ans += grid[i][j] != grid[i][m - j - 1];
            }
        }
        return ans;
    }

    int forCol(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n / 2; i++) {
                ans += grid[i][j] != grid[n - i - 1][j];
            }
        }
        return ans;
    }
public:
    int minFlips(vector<vector<int>>& grid) {
        return min(forLine(grid), forCol(grid));
    }
};