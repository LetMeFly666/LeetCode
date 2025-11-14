/*
 * @Author: LetMeFly
 * @Date: 2025-11-14 17:51:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-11-14 18:07:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1));
        for (vector<int>& q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            diff[x1][y1]++;
            diff[x2 + 1][y1]--;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y2 + 1]++;
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = diff[i][j] 
                            + (i == 0 ? 0 : ans[i - 1][j])
                            + (j == 0 ? 0 : ans[i][j - 1])
                            - ((i == 0 || j == 0) ? 0 : ans[i - 1][j - 1]);
            }
        }
        return ans;
    }
};