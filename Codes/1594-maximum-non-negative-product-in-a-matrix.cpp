/*
 * @Author: LetMeFly
 * @Date: 2026-03-23 21:32:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-23 21:45:04
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

// THIS CANNOT BE ACCEPTED
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> maximum(n, vector<ll>(m));
        vector<vector<ll>> minimum(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll left_max = j ? maximum[i][j - 1] : 1;
                ll left_min = j ? minimum[i][j - 1] : 1;
                ll up_max = i ? maximum[i - 1][j] : 1;
                ll up_min = i ? minimum[i - 1][j] : 1;
                if (grid[i][j] >= 0) {
                    maximum[i][j] = max(left_max, up_max) * grid[i][j] % MOD;
                    minimum[i][j] = max(left_min, up_min) * grid[i][j] % MOD;
                } else {
                    maximum[i][j] = max(left_min, up_min) * grid[i][j] % MOD;
                    minimum[i][j] = max(left_max, up_max) * grid[i][j] % MOD;
                }
            }
        }
        return maximum[n - 1][m - 1] >= 0 ? maximum[n - 1][m - 1] : -1;
    }
};