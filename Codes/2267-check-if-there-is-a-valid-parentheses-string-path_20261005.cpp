#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef bitset<201> State;

class Solution {
private:
    void update(State& from, State& to, bool is_left) {
        if (is_left) {
            to |= from << 1;
        } else {
            to |= from >> 1;
        }
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<State>> dp(n, vector<State>(m));
        if (grid[0][0] == ')') {
            return false;
        }
        dp[0][0].set(1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) {
                    update(dp[i - 1][j], dp[i][j], grid[i][j] == '(');
                }
                if (j) {
                    update(dp[i][j - 1], dp[i][j], grid[i][j] == '(');
                }
            }
        }

        return dp[n - 1][m - 1].test(0);
    }
};
