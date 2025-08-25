/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-25 21:39:42
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0, j = 0, d = 1;
        int total = mat.size() * mat[0].size();
        while (ans.size() < total) {
            ans.push_back(mat[i][j]);
            if (d) {
                i--, j++;
                if (i == -1) {
                    i = 0;
                } else if (j == mat[0].size()) {
                    j = mat[0].size() - 1;
                }
            } else {
                i++, j--;
                if (j == -1) {
                    j = 0;
                } else if (i == mat.size()) {
                    i = mat.size() - 1;
                }
            }
        }
        return ans;
    }
};