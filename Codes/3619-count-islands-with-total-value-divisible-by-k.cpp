/*
 * @Author: LetMeFly
 * @Date: 2026-10-26 21:57:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-26 22:03:01
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, m;
    static constexpr int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool inGrid(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }

    bool bfs(vector<vector<int>>& grid, int x, int y, int k) {
        int cnt = grid[x][y];
        grid[x][y] = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (inGrid(nx, ny) && grid[nx][ny]) {
                    cnt += grid[nx][ny];
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
        return cnt % k == 0;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    ans += bfs(grid, i, j, k);
                }
            }
        }
        return ans;
    }
};
