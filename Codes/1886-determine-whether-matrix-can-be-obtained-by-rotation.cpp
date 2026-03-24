/*
 * @Author: LetMeFly
 * @Date: 2026-03-22 23:35:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-22 23:45:34
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int t = 0; t < 4; t++) {
            if (mat == target) {
                return true;
            }
            if (t == 4) {
                break;
            }
            vector<vector<int>> tmp(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tmp[i][j] = mat[j][n - i - 1];
                }
            }
            mat.swap(tmp);
        }
        return false;
    }
};
