/*
 * @Author: LetMeFly
 * @Date: 2022-04-18 15:06:47
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-04-18 15:19:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat[0].size() * mat.size())
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int locI = 0, locJ = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = mat[locI][locJ++];
                if (locJ == mat[0].size()) {
                    locI++, locJ = 0;
                }
            }
        }
        return ans;
    }
};