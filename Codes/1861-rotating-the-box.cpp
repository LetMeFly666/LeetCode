/*
 * @Author: LetMeFly
 * @Date: 2026-05-06 19:54:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-06 20:00:01
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        for (int i = 0; i < n; i++) {
            for (int start = 0, now = 0, cnt = 0; now <= m; now++) {
                if (now == m || boxGrid[i][now] == '*') {  // 障碍
                    int empty = now - start - cnt;
                    for (int j = start; j < start + empty; j++) {
                        boxGrid[i][j] = '.';
                    }
                    for (int j = start + empty; j < now; j++) {
                        boxGrid[i][j] = '#';
                    }
                    start = now + 1;
                    cnt = 0;
                } else {
                    cnt += boxGrid[i][now] == '#';
                }
            }
        }

        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};
