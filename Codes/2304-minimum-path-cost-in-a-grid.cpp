/*
 * @Author: LetMeFly
 * @Date: 2023-11-22 19:55:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-22 20:44:45
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int m_ = 100000000;
                for (int k = 0; k < m; k++) {
                    m_ = min(m_, grid[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                grid[i][j] += m_;
            }
        }
        return *min_element(grid[0].begin(), grid[0].end());
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