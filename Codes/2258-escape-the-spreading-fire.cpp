/*
 * @Author: LetMeFly
 * @Date: 2023-11-09 22:46:38
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-09 23:12:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int m, n;
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void debug(vector<vector<int>>& v) {
        for (auto& t : v) {
            for (auto& tt : t) {
                cout << tt << ' ';
            }
            cout << endl;
        }
    }

    bool bfsFire(vector<vector<int>>& graph, int t) {  // 让所有的火燃烧t秒。如果最后一秒之前火已经到达了安全屋则返回false
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        while (t--) {
            int fireNum = q.size();
            while (fireNum--) {
                auto&& [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = x + direction[d][0];
                    int ty = y + direction[d][1];
                    if (tx >= 0 && tx < m && ty >= 0 && ty < n && graph[tx][ty] == 0) {
                        graph[tx][ty] = 1;
                        q.push({tx, ty});
                    }
                }
            }
            if (t && graph[m - 1][n - 1] == 1) {  // 没有到t秒，火已经烧到了安全屋，不行了
                return false;
            }
        }
        return true;
    }

    bool bfsPeople(vector<vector<int>>& graph) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        graph[0][0] = 2;
        while (q.size()) {
            auto&& [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = x + direction[d][0];
                int ty = y + direction[d][1];
                if (tx >= 0 && tx < m && ty >= 0 && ty < n && !graph[tx][ty]) {
                    graph[tx][ty] = 2;
                    q.push({tx, ty});
                    if (tx == m - 1 && ty == n - 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool check(vector<vector<int>>& grid, int t) {
        vector<vector<int>> graph = grid;
        bool canContinue = bfsFire(graph, t);
        if (t == 4) {
            debug(graph);
        }
        if (!canContinue) {
            return false;
        }
        return bfsPeople(graph);
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
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
    vector<vector<int>> graph = {{0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 2, 1, 0}, {0, 2, 0, 0, 1, 2, 0}, {0, 0, 2, 2, 2, 0, 2}, {0, 0, 0, 0, 0, 0, 0}};
    cout << sol.maximumMinutes(graph) << endl;
    return 0;
}
#endif