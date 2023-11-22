/*
 * @Author: LetMeFly
 * @Date: 2023-11-22 19:55:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-22 20:17:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int m_ = 100000000;
                for (int k = 0; k < m; k++) {
                    // printf("grid[%d][%d], moveCost[%d][%d]\n", i - 1, k, grid[i - 1][k], j);
                    m_ = min(m_, grid[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
                cout << m_ << endl;
                grid[i][j] += m_;
            }
        }
        return *min_element(grid.back().begin(), grid.back().end());
    }
};

#ifdef _WIN32
int main() {
    Solution sol;
    
    vector<vector<int>> grid = {{5, 3}, {4, 0}, {2, 1}};
    vector<vector<int>> moveCost = {{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
    cout << sol.minPathCost(grid, moveCost) << endl;

    return 0;
}
#endif