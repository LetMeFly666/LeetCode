/*
 * @Author: LetMeFly
 * @Date: 2025-10-06 12:17:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-06 12:31:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1) {
            return grid[0][0];  // while的判断逻辑是入队时判断是否是终点
        }
        auto cmp = [&grid](pair<int, int>& a, pair<int, int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];  // val小的优先
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited(n, vector<bool>(m));
        pq.push({0, 0});
        visited[0][0] = true;
        while (true) {
            auto [x, y] = pq.top();
            pq.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + direction[d][0], ny = y + direction[d][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                    continue;
                }
                grid[nx][ny] = max(grid[nx][ny], grid[x][y]);
                if (nx == n - 1 && ny == m - 1) {
                    return grid[nx][ny];
                }
                visited[nx][ny] = true;
                pq.push({nx, ny});
            }
        }
    }
};