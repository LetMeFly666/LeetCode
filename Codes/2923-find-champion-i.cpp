/*
 * @Author: LetMeFly
 * @Date: 2024-04-12 13:42:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-04-12 13:42:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int j = 0; j < n; j++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return j;
            }
        }
        return -1;  // Fake Return
    }
};