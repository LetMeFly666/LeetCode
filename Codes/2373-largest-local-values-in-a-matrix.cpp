/*
 * @Author: LetMeFly
 * @Date: 2023-03-01 09:11:24
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-01 09:13:33
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < n; j++) {
                int M = 1;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        M = max(M, grid[i + k][j + l]);
                    }
                }
                ans[i - 1][j - 1] = M;
            }
        }
        return ans;
    }
};