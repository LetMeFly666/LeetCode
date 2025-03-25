/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 16:52:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 17:42:27
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                unordered_set<int> l, r;
                for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
                    l.insert(grid[i - k][j - k]);
                }
                for (int k = 1; i + k < grid.size() && j + k < grid[0].size(); k++) {
                    r.insert(grid[i + k][j + k]);
                }
                ans[i][j] = abs(int(l.size() - r.size()));
            }
        }
        return ans;
    }
};