/*
 * @Author: LetMeFly
 * @Date: 2026-07-14 11:11:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-14 11:26:09
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
class Solution {
private:
    constexpr static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> costs(n, vector<int>(m, 100000000));
        deque<pii> q;
        q.push_back({0, 0});
        costs[0][0] = grid[0][0];  // 注意起点可能直接掉血
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    int next_cost = costs[x][y] + grid[nx][ny];
                    if (next_cost >= costs[nx][ny]) {
                        continue;
                    }
                    costs[nx][ny] = next_cost;
                    if (grid[nx][ny]) {
                        q.push_back({nx, ny});
                    } else {
                        q.push_front({nx, ny});
                    }
                }
            }
        }
        return costs[n - 1][m - 1] < health;
    }
};
