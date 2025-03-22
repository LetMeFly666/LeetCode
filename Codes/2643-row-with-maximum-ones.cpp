/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 22:42:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 22:43:30
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mx = 0, ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                cnt += mat[i][j];
            }
            if (cnt > mx) {
                mx = cnt;
                ans = i;
            }
        }
        return {ans, mx};
    }
};