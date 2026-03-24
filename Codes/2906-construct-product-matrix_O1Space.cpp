/*
 * @Author: LetMeFly
 * @Date: 2026-03-24 22:02:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-24 22:07:50
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

        vector<vector<int>> ans(n, vector<int>(m, 1));
        for (int t = 1; t < m * n; t++) {
            auto [i1, j1] = getIndex(t);
            auto [i0, j0] = getIndex(t - 1);
            ans[i1][j1] = (ll)ans[i0][j0] * grid[i0][j0] % MOD;
        }

        ll suffix = 1;
        for (int t = m * n - 2; t >= 0; t--) {
            auto [i0, j0] = getIndex(t);
            auto [i1, j1] = getIndex(t + 1);
            suffix = suffix * grid[i1][j1] % MOD;
            ans[i0][j0] = ans[i0][j0] * suffix % MOD;
        }
        return ans;
    }
};