/*
 * @Author: LetMeFly
 * @Date: 2022-10-25 11:57:14
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-25 12:12:00
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
#define dbg(x) cout << #x << " = " << x << endl
#endif

typedef pair<int, int> pii;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    queue<pii> q;
                    grid[i][j] = -1;
                    q.push({i, j});
                    ans += 4;
                    while (q.size()) {
                        pii thisNode = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int tx = thisNode.first + directions[d][0];
                            int ty = thisNode.second + directions[d][1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                if (grid[tx][ty]) {
                                    ans--;
                                    // dbg(ans);  //********
                                    if (grid[tx][ty] == 1) {
                                        grid[tx][ty] = -1;
                                        q.push({tx, ty});
                                        ans += 4;
                                    }
                                }
                            }
                        }
                    }

                    goto loop;
                }
            }
        }
        loop:;
        return ans;
    }
};