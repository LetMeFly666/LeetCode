/*
 * @Author: LetMeFly
 * @Date: 2023-07-13 08:11:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-07-13 08:16:21
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m = 1e8;
                for (int k = -1; k <= 1; k++) {
                    if (j + k >= 0 && j + k < n) {
                        m = min(m, matrix[i - 1][j + k]);
                    }
                }
                matrix[i][j] += m;
            }
        }
        int ans = 1e8;
        for (int j = 0; j < n; j++) {
            ans = min(ans, matrix[n - 1][j]);
        }
        return ans;
    }
};