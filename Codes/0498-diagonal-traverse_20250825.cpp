/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-25 21:59:34
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        for (int k = 0; k < m + n - 1; k++) {
            if (k % 2) {
                for (int i = 0, j = k; j >= 0; i++, j--) {
                    ans.push_back(mat[i][j]);
                }
            } else {
                for (int i = k, j = 0; i >= 0; i--, j++) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};