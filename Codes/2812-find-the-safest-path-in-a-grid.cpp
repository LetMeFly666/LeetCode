/*
 * @Author: LetMeFly
 * @Date: 2026-07-01 17:16:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-01 17:54:30
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif
#define debug_(x) {cout << #x << ":" << endl; debug(x);}

typedef pair<int, int> pii;
class Solution {
private:
    vector<vector<int>> dis;
    static constexpr int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void genDis(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        dis = vector<vector<int>>(n, vector<int>(m));
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny <m && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }

    vector<vector<int>> bfs(int x, int y) {
        int n = dis.size(), m = dis[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<pii> q;
        q.push({x, y});
        res[x][y] = dis[x][y];
        visited[x][y] = true;

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny <m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    res[nx][ny] = min(dis[nx][ny], res[x][y]);
                }
            }
        }
        return res;
    }

    int bfs() {
        int n = dis.size(), m = dis[0].size();
        vector<vector<int>> start = bfs(0, 0);
        vector<vector<int>> end = bfs(n - 1, m - 1);
        debug_(dis);
        debug_(start);
        debug_(end);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, min(start[i][j], end[i][j]));
            }
        }
        return ans;
    }

    void debug(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cout << "[[";
            } else {
                cout << " [";
            }

            for (int j = 0; j < m; j++) {
                if (j) {
                    cout << ", ";
                }
                cout << v[i][j];
            }

            if (i == n - 1) {
                cout << "]]";
            } else {
                cout << "],";
            }
            puts("");
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        genDis(grid);
        return bfs();
    }
};
