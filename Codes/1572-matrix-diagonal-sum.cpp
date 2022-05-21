/*
 * @Author: LetMeFly
 * @Date: 2022-04-18 15:03:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-18 15:05:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            if (i == n - i - 1) {
                ans -= mat[i][i];
            }
            ans += mat[i][i] + mat[i][n - i - 1];
        }
        return ans;
    }
};