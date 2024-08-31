/*
 * @Author: LetMeFly
 * @Date: 2024-08-31 17:27:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-31 17:29:58
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid.size(); j++) {
                if ((grid[i][j] == 'W') + (grid[i - 1][j] == 'W') + (grid[i][j - 1] == 'W') + (grid[i - 1][j - 1] == 'W') != 2) {
                    return true;
                }
            }
        }
        return false;
    }
};