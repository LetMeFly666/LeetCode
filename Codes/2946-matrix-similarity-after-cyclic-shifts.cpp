/*
 * @Author: LetMeFly
 * @Date: 2026-03-27 08:48:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-27 08:49:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();
        for (vector<int>& row : mat) {
            for (int j = 0; j < m; j++) {
                if (row[j] != row[(j + k) % m]) {
                    return false;
                }
            }
        }
        return true;
    }
};