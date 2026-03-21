/*
 * @Author: LetMeFly
 * @Date: 2026-03-20 23:10:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-21 09:35:34
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                vector<int> vals;
                vals.reserve(k * k);
                for (int di = 0; di < k; di++) {
                    for (int dj = 0; dj < k; dj++) {
                        vals.push_back(grid[i + di][j + dj]);
                    }
                }
                sort(vals.begin(), vals.end());
                int diff = 1000000;
                for (int idx = 1; idx < k * k; idx++) {
                    int this_diff = vals[idx] - vals[idx - 1];
                    if (this_diff) {
                        diff = min(diff, this_diff);
                    }
                }
                ans[i][j] = diff == 1000000 ? 0 : diff;
            }
        }
        return ans;
    }
};