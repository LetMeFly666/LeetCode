/*
 * @Author: LetMeFly
 * @Date: 2023-06-18 13:10:36
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-06-18 13:32:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
    void mark(vector<vector<int>>& grid, int x, int y) {
        queue<pii> q;
        q.push({x, y});
        grid[x][y] = 1;
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = x + directions[d][0];
                int ty = y + directions[d][1];
                if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty] == 0) {
                    q.push({tx, ty});
                    grid[tx][ty] = 1;
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // 四周的0视为1
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                mark(grid, i, 0);
            }
            if (grid[i][grid[0].size() - 1] == 0) {
                mark(grid, i, grid[0].size() - 1);
            }
        }
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[0][j] == 0) {
                mark(grid, 0, j);
            }
            if (grid[grid.size() - 1][j] == 0) {
                mark(grid, grid.size() - 1, j);
            }
        }
        // 统计中间岛屿数量
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                if (grid[i][j] == 0) {
                    mark(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};