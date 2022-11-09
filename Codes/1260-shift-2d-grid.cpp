/*
 * @Author: LetMeFly
 * @Date: 2022-07-20 11:05:16
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-20 11:25:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

#ifdef FirstTry
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        while (k--) {
            int last = grid[n - 1][m - 1];
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j > 0; j--) {
                    grid[i][j] = grid[i][j - 1];
                }
                if (i > 0)
                    grid[i][0] = grid[i - 1][m - 1];
                else
                    grid[i][0] = last;
            }
        }
        return grid;
    }
};
#else  // FirstTry
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m;
        vector<vector<int>> ans = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int originalTh = i * m + j;
                int newTh = (originalTh + k) % size;
                ans[newTh / m][newTh % m] = grid[i][j];
            }
        }
        return ans;
    }
};
#endif  // FirstTry