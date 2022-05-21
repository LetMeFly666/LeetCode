/*
 * @Author: LetMeFly
 * @Date: 2022-04-26 08:57:54
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-26 09:00:46
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        // int ans = n * n;  // 不可以！可能有的高度为0
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int M = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans++;
                }
                M = max(M, grid[i][j]);
            }
            ans += M;
        }
        for (int j = 0; j < n; j++) {
            int M = 0;
            for (int i = 0; i < n; i++) {
                M = max(M, grid[i][j]);
            }
            ans += M;
        }
        return ans;
    }
};