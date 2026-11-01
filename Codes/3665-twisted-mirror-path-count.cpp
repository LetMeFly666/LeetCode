/*
 * @Author: LetMeFly
 * @Date: 2026-11-01 11:18:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-01 11:36:06
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
constexpr ll MOD = 1e9 + 7;
class Solution {
private:
    void transfer(const ll& a, ll& b) {
        b = (a + b) % MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> dp(n, vector<ll>(m));
        vector<vector<ll>> up(n, vector<ll>(m));
        vector<vector<ll>> left(n, vector<ll>(m));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {  // 镜子
                    if (i) {  // left
                        transfer(grid[i - 1][j] ? up[i - 1][j] : dp[i - 1][j], left[i][j]);
                    }
                    if (j) {  // up
                        transfer(grid[i][j - 1] ? left[i][j - 1] : dp[i][j - 1], up[i][j]);
                    }
                } else {  // 空白
                    if (i) {  // left
                        transfer(grid[i - 1][j] ? up[i - 1][j] : dp[i - 1][j], dp[i][j]);
                    }
                    if (j) {  // up
                        transfer(grid[i][j - 1] ? left[i][j - 1] : dp[i][j - 1], dp[i][j]);
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
