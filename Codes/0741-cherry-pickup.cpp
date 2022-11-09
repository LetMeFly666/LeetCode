/*
 * @Author: LetMeFly
 * @Date: 2022-07-10 10:30:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-10 10:36:32
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

// class Solution {
// public:
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2 * n - 1, 0)));
//         for (int x1 = 0; x1 < n; x1++) {
            
//         }
//         return dp[n - 1][n - 1][2 * n - 2];
//     }
// };

// Copy
// https://leetcode.cn/problems/cherry-pickup/solution/zhai-ying-tao-by-leetcode-solution-1h3k/
// https://leetcode.cn/problems/cherry-pickup/solution/zhao-by-jiang-hui-4-kkxj/
class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2) {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; // 都往右
                    if (x1) {
                        res = max(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                    }
                    if (x2) {
                        res = max(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }
};