/*
 * @Author: LetMeFly
 * @Date: 2026-10-25 09:03:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-25 09:17:30
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int n, m;
    static constexpr int dirs[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    bool isCenter(int i, int j) {  // 是否不是四周这一圈
        return i && i != n - 1 && j && j != m - 1;
    }

    bool inGrid(int i, int j) {
        return i >= 0 && i < n && j >=0 && j < m;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    continue;
                }
                // 新土地
                grid[i][j] = 1;
                bool ok = isCenter(i, j);
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto[dx, dy] : dirs) {
                        int nx = x + dx, ny = y + dy;
                        if (!inGrid(nx, ny) || grid[nx][ny]) {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        ok &= isCenter(nx, ny);
                        q.push({nx, ny});
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};
