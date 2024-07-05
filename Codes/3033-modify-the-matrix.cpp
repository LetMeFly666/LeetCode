/*
 * @Author: LetMeFly
 * @Date: 2024-07-05 21:39:17
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-05 21:39:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix[0].size(); j++) {
            int M = matrix[0][j];
            for (int i = 1; i < matrix.size(); i++) {
                M = max(M, matrix[i][j]);
            }
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = M;
                }
            }
        }
        return matrix;
    }
};