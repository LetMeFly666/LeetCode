/*
 * @Author: LetMeFly
 * @Date: 2025-12-28 14:33:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-28 14:44:29
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        int j = 0;
        for (; j < m; j++) {
            if (grid[0][j] < 0) {
                break;
            }
        }
        if (j == m) {
            j--;
        }

        for (int i = 0; i < n; i++) {
            while (j >= 0 && grid[i][j] < 0) {
                j--;
            }
            // printf("i = %d, j = %d, m - j - 1 = %d\n", i, j, m - j - 1);
            ans += m - j - 1;
        }
        return ans;
    }
};

/*
[[4,3,2,-1],
 [3,2,1,-1],
 [1,1,-1,-2],
 [-1,-1,-2,-3]]
*/