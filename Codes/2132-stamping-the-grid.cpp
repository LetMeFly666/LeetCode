/*
 * @Author: LetMeFly
 * @Date: 2023-12-14 14:43:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-14 14:49:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            int last = -1;
            for (int j = 0; j <= m; j++) {
                if (j == m || grid[i][j] == 1) {
                    if (j - last - 1 && j - last - 1 < stampWidth) {
                        return false;
                    }
                    last = j;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            int last = -1;
            for (int i = 0; i <= n; i++) {
                if (i == n || grid[i][j] == 1) {
                    if (i - last - 1 && i - last - 1 < stampHeight) {
                        return false;
                    }
                    last = i;
                }
            }
        }
        return true;
    }
};

/*
[[0,0,0,0,0],[0,0,0,0,0],[0,0,1,0,0],[0,0,0,0,1],[0,0,0,1,1]] 2 2

false
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 0 0 1 1
*/