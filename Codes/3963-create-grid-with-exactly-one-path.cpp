/*
 * @Author: LetMeFly
 * @Date: 2026-10-27 13:05:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-27 13:08:16
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for (int i = 0; i < m; i++) {
            ans[i][0] = '.';
        }
        for (int j = 0; j < n; j++) {
            ans[m - 1][j] = '.';
        }
        return ans;
    }
};