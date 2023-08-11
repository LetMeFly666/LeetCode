/*
 * @Author: LetMeFly
 * @Date: 2023-08-11 07:55:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-11 07:58:43
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += mat[i][i] + mat[i][n - i - 1];
        }
        if (n % 2) {
            ans -= mat[n / 2][n / 2];
        }
        return ans;
    }
};