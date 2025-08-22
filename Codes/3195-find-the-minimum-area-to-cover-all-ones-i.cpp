/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:20:03
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = 1000, r = 0, u = 1000, d = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    l = min(l, j);
                    r = max(r, j);
                    u = min(u, i);
                    d = max(d, j);
                }
            }
        }
        return (r - l + 1) * (d - u + 1);
    }
};