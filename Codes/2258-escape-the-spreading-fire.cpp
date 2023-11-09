/*
 * @Author: LetMeFly
 * @Date: 2023-11-09 22:46:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-10 00:03:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int m, n;
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> fireTime;
    void debug(vector<vector<int>>& v) {
        for (auto& t : v) {
            for (auto& tt : t) {
                cout << tt << ' ';
            }
            cout << endl;
        }
    }

    void bfsFire(vector<vector<int>>& grid) {  // 计算火燃烧到每个位置时所需耗时并存入fireTime
        vector<vector<int>> graph = grid;
        fireTime = vector<vector<int>>(m, vector<int>(n, 1e9));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    q.push({i, j});
                    fireTime[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            auto&& [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = x + direction[d][0];
                int ty = y + direction[d][1];
                if (tx >= 0 && tx < m && ty >= 0 && ty < n && !graph[tx][ty]) {
                    graph[tx][ty] = 1;
                    fireTime[tx][ty] = fireTime[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }

    bool check(vector<vector<int>>& grid, int t) {  // 其实是bfsPeople
        vector<vector<int>> peopleTime(m, vector<int>(n, 0)), graph(grid);
        peopleTime[0][0] = t;
        queue<pair<int, int>> q;
        q.push({0, 0});
        graph[0][0] = 2;
        while (q.size()) {
            auto&& [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = x + direction[d][0];
                int ty = y + direction[d][1];
                int toTime = peopleTime[x][y] + 1;
                if (tx >= 0 && tx < m && ty >= 0 && ty < n && !graph[tx][ty]) {
                    graph[tx][ty] = 2;
                    if (tx == m - 1 && ty == n - 1 && toTime <= fireTime[m - 1][n - 1]) {
                        return true;
                    }
                    if (toTime < fireTime[tx][ty]) {
                        peopleTime[tx][ty] = toTime;
                        q.push({tx, ty});
                    }
                }
            }
        }
        return false;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        bfsFire(grid);
        int l = 0, r = n * m;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(grid, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans >= n * m ? 1e9 : ans;
    }
};

#ifdef _WIN32
int main() {
    Solution sol;
    // vector<vector<int>> graph = {{0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 2, 1, 0}, {0, 2, 0, 0, 1, 2, 0}, {0, 0, 2, 2, 2, 0, 2}, {0, 0, 0, 0, 0, 0, 0}};
    /*
    0 0 0
    2 2 0
    1 2 0
    */
    // vector<vector<int>> graph = {{0, 0, 0}, {2, 2, 0}, {1, 2, 0}};
    /*
    0 1 1 1 0 1
    2 1 0 2 0 2
    1 2 0 2 0 2
    1 1 1 1 1 1
    2 0 0 2 2 0
    0 0 1 1 0 2
    0 1 1 0 1 0
    1 2 2 1 2 2
    0 2 2 1 2 1
    1 1 2 0 2 0
    0 2 0 1 1 1
    1 0 1 1 0 0
    1 2 2 0 2 2
    1 1 1 1 1 2
    0 0 0 0 0 0
    1 2 0 1 2 1
    1 2 2 0 1 1
    1 1 2 1 1 0
    0 0 0 0 2 1
    1 2 2 2 2 0
    2 0 1 0 1 0
    0 0 2 2 2 0
    */
    vector<vector<int>> graph = {{0, 1, 1, 1, 0, 1}, {2, 1, 0, 2, 0, 2}, {1, 2, 0, 2, 0, 2}, {1, 1, 1, 1, 1, 1}, {2, 0, 0, 2, 2, 0}, {0, 0, 1, 1, 0, 2}, {0, 1, 1, 0, 1, 0}, {1, 2, 2, 1, 2, 2}, {0, 2, 2, 1, 2, 1}, {1, 1, 2, 0, 2, 0}, {0, 2, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 0}, {1, 2, 2, 0, 2, 2}, {1, 1, 1, 1, 1, 2}, {0, 0, 0, 0, 0, 0}, {1, 2, 0, 1, 2, 1}, {1, 2, 2, 0, 1, 1}, {1, 1, 2, 1, 1, 0}, {0, 0, 0, 0, 2, 1}, {1, 2, 2, 2, 2, 0}, {2, 0, 1, 0, 1, 0}, {0, 0, 2, 2, 2, 0}};
    cout << sol.maximumMinutes(graph) << endl;
    return 0;
}
#endif