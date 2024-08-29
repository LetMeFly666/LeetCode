/*
 * @Author: LetMeFly
 * @Date: 2024-08-29 23:17:03
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-29 23:18:11
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (j && grid[0][j] == grid[0][j - 1]) {
                return false;
            }
            for (int i = 1; i < grid.size(); i++) {
                if (grid[i][j] != grid[i - 1][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};