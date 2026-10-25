/*
 * @Author: LetMeFly
 * @Date: 2026-10-25 09:03:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-25 09:13:47
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
        vector<vector<bool>> visited(n, vector<bool>(m));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] || visited[i][j]) {
                    continue;
                }
                // 新土地
                visited[i][j] = true;
                bool ok = isCenter(i, j);
                for (auto[di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if (!inGrid(ni, nj) || visited[di][dj] || ) {
                        continue;
                    }

                }
            }
        }
        return ans;
    }
};
