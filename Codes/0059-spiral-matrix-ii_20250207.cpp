/*
 * @Author: LetMeFly
 * @Date: 2025-02-07 20:37:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 20:42:22
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int d = 0, x = 0, y = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx < 0 || nx == n || ny < 0 || ny == n || ans[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + directions[d][0];
                ny = y + directions[d][1];
            }
            x = nx, y = ny;
        }
        return ans;
    }
};