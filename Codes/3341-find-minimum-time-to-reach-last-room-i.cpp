/*
 * @Author: LetMeFly
 * @Date: 2025-05-07 23:27:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-08 21:45:08
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    static constexpr int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 2000000000));
        ans[0][0] = 0;
        priority_queue<tuple<int, int, int>> pq;  // [<-t, x, y>, ...]
        pq.push({0, 0, 0});
        while (pq.size()) {
            auto [t, x, y] = pq.top();
            t = -t;
            pq.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int nt = max(t, moveTime[nx][ny]) + 1;
                if (nt < ans[nx][ny]) {
                    ans[nx][ny] = nt;
                    pq.push({-nt, nx, ny});
                }
            }
        }
        return ans[n - 1][m - 1];
    }
};