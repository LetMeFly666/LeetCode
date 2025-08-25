/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-25 21:49:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0, j = 0;
        bool d = true;
        int total = mat.size() * mat[0].size();
        while (ans.size() < total) {
            printf("i = %d, j = %d, d = %d\n", i, j, d);  // *****
            ans.push_back(mat[i][j]);
            if (d) {
                i--, j++;
                if (i == -1 || j == mat[0].size()) {
                    d = !d;
                }
                if (i == -1) {
                    i = 0;
                }
                if (j == mat[0].size()) {
                    j = mat[0].size() - 1;
                }
            } else {
                i++, j--;
                if (j == -1 || i == mat.size()) {
                    d = !d;
                }
                if (j == -1) {
                    j = 0;
                }
                if (i == mat.size()) {
                    i = mat.size() - 1;
                }
            }
        }
        return ans;
    }
};