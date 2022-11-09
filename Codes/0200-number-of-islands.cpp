/*
 * @Author: LetMeFly
 * @Date: 2022-08-18 09:50:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-18 09:57:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
public:
    int numIslands(vector<vector<char>>& grid) {  // '2'表示遍历过的岛屿
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '2';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (q.size()) {
                        auto[x, y] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int tx = x + direction[d][0];
                            int ty = y + direction[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (grid[tx][ty] == '1') {
                                    grid[tx][ty] = '2';
                                    q.push({tx, ty});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};