/*
 * @Author: LetMeFly
 * @Date: 2026-03-24 21:47:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-24 22:02:21
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto getIndex = [&](const int& t) {
            return pair<int, int>{t / m, t % m};
        };

        vector<vector<ll>> prefix(n, vector<ll>(m, 1));
        for (int t = 1; t < m * n; t++) {
            auto [i1, j1] = getIndex(t);
            auto [i0, j0] = getIndex(t - 1);
            prefix[i1][j1] = prefix[i0][j0] * grid[i0][j0] % MOD;
        }

        vector<vector<ll>> suffix(n, vector<ll>(m, 1));
        for (int t = m * n - 2; t >= 0; t--) {
            auto [i0, j0] = getIndex(t);
            auto [i1, j1] = getIndex(t + 1);
            suffix[i0][j0] = suffix[i1][j1] * grid[i1][j1] % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = prefix[i][j] * suffix[i][j] % MOD;
            }
        }
        return ans;
    }
};