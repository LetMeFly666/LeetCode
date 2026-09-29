/*
 * @Author: LetMeFly
 * @Date: 2026-09-29 08:15:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-09-29 08:40:37
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef bitset<201> states;
class Solution {
private:
    void modify(states& now, states& from, bool is_more) {
        if (is_more) {
            now |= from << 1;
        } else {
            now |= from >> 1;
        }
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<states>> dp(n, vector<states>(m));
        if (grid[0][0] == ')') {
            return false;
        }
        dp[0][0].set(1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool is_more = dp[i][j] == '(';
                if (i) {
                    modify(dp[i][j], dp[i - 1][j], is_more);
                }
                if (j) {
                    modify(dp[i][j], dp[i][j - 1], is_more);
                }
            }
        }
        return dp[n - 1][m - 1].test(0);
    }
};
