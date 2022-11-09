/*
 * @Author: LetMeFly
 * @Date: 2022-10-25 09:44:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-25 10:47:15
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef pair<int, int> pii;
const static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
private:
    // vector<vector<int>> distance;
    int n;

    queue<pii> getIslandBy1Node(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = -1;
        queue<pii> q, ans;
        q.push({x, y});
        ans.push({x, y});
        while (q.size()) {
            pii thisNode = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int tx = thisNode.first + directions[d][0];
                int ty = thisNode.second + directions[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                    if (grid[tx][ty] == 1) {
                        grid[tx][ty] = -1;
                        q.push({tx, ty});
                        ans.push({tx, ty});
                    }
                }
            }
        }
        return ans;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        // distance = vector<vector<int>>(n, vector<int>(n));
        queue<pii> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q = getIslandBy1Node(i, j, grid);
                    goto loop;
                }
            }
        }
        loop:;
        int ans = 0;
        while (true) {
            for (int i = q.size(); i > 0; i--) {
                pii thisNode = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int tx = thisNode.first + directions[d][0];
                    int ty = thisNode.second + directions[d][1];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                        if (grid[tx][ty] == 1) {
                            return ans;
                        }
                        if (grid[tx][ty] == 0) {
                            grid[tx][ty] = -1;
                            q.push({tx, ty});
                        }
                    }
                }
            }
            ans++;
        }
        // return -1;  // FakeReturn
    }
};