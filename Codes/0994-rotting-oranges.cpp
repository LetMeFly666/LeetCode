/*
 * @Author: LetMeFly
 * @Date: 2024-05-13 14:00:00
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-05-13 14:11:25
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int cntNormal = 0;
        queue<int> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    cntNormal++;
                }
                else if (grid[i][j] == 2) {
                    q.push(i * 10 + j);
                    grid[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            bool hasNew = false;
            for (int i = q.size(); i > 0; i--) {
                int x = q.front() / 10, y = q.front() % 10;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + directions[d][0], ty = y + directions[d][1];
                    if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty] == 1) {
                        grid[tx][ty] = 0;
                        q.push(tx * 10 + ty);
                        cntNormal--;
                        hasNew = true;
                    }
                }
            }
            ans += hasNew;
        }
        return cntNormal ? -1 : ans;
    }
};