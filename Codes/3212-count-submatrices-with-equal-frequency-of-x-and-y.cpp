/*
 * @Author: LetMeFly
 * @Date: 2026-03-19 22:10:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-19 22:19:31
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int v(int x) {
        return x == 'X' ? 1 : x == 'Y' ? -1 : 0;
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> hasX(n, vector<bool>(m));  // has x or y
        vector<vector<int>> diff(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && j) {
                    hasX[i][j] = hasX[i - 1][j] | hasX[i][j - 1] | (grid[i][j] != '.');
                    diff[i][j] = diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1] + v(grid[i][j]);
                } else if (i) {
                    hasX[i][j] = hasX[i - 1][j] | (grid[i][j] != '.');
                    diff[i][j] = diff[i - 1][j] + v(grid[i][j]);
                } else if (j) {
                    hasX[i][j] = hasX[i][j - 1] | (grid[i][j] != '.');
                    diff[i][j] = diff[i][j - 1] + v(grid[i][j]);
                } else {
                    hasX[i][j] = grid[i][j] != '.';
                    diff[i][j] = v(grid[i][j]);
                }
                ans += (!diff[i][j] && hasX[i][j]);
            }
        }
        return ans;
    }
};