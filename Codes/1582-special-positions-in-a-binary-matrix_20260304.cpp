/*
 * @Author: LetMeFly
 * @Date: 2026-03-04 23:58:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-05 00:02:09
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            bool only1 = true;
            int idx = -1;
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    if (idx != -1) {
                        only1 = false;
                        break;
                    }
                    idx = j;
                }
            }
            if (!only1 || idx == -1) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (mat[k][idx] && k != i) {
                    only1 = false;
                    break;
                }
            }
            ans += only1;
        }
        return ans;
    }
};