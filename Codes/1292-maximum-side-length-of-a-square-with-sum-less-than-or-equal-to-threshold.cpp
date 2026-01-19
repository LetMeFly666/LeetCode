/*
 * @Author: LetMeFly
 * @Date: 2026-01-19 21:47:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-19 21:55:16
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = mat[i][j] - prefix[i][j] + prefix[i][j + 1] + prefix[i + 1][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (i + ans < n && j + ans < m && prefix[i + ans + 1][j + ans + 1] - prefix[i + ans + 1][j] - prefix[i][j + ans + 1] + prefix[i][j] <= threshold) {
                    ans++;
                }
            }
        }
        return ans;
    }
};