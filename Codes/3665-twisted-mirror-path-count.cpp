/*
 * @Author: LetMeFly
 * @Date: 2026-11-01 11:18:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-01 11:31:28
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
                    
                } else {  // 空白
                    if (i && !grid[i - 1][j]) {  // 左空白
                        transfer(dp[i - 1][j], dp[i][j]);
                    } else if (i && grid[i - 1][j])
                }
            }
        }
    }
};
