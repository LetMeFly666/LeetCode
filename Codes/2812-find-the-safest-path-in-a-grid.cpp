/*
 * @Author: LetMeFly
 * @Date: 2026-07-01 17:16:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-01 22:47:08
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

    int dfs() {
        int n = dis.size(), m = dis[0].size();
        queue<pii> q;
        vector<vector<bool>> visited;
        q.push({0, 0});
        visited[0][0] = true;
        if (n == 1 && m == 1) {
            return dis[0][0];
        }
        int start = min(dis[0][0], dis[n - 1][m - 1]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dis[i][j] >= start) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        while (true) {
            queue<pii> q2;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + directions[d][0];
                    int ny = y + directions[d][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                        if (dis[nx][ny] <= start) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            if (nx == n - 1 && ny == m - 1) {
                                return start;
                            }
                        } else if (dis[nx][ny] == start + 1) {
                            q2.push(...)
                            ...
                        }
                    }
                }
            }
            start++;
            swap(q, q2);
        }
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
        return dfs();
    }
};

// 忽然发现其实m=n
