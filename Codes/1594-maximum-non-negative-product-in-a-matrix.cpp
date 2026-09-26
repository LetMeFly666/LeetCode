/*
 * @Author: LetMeFly
 * @Date: 2026-03-23 21:32:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-23 22:00:02
 */
#ifdef _DEBUG
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> maximum(n, vector<ll>(m));
        vector<vector<ll>> minimum(n, vector<ll>(m));

        maximum[0][0] = minimum[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maximum[i][0] = minimum[i][0] = maximum[i - 1][0] * grid[i][0];
        }
        for (int j = 1; j < m; j++) {
            maximum[0][j] = minimum[0][j] = maximum[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] >= 0) {
                    maximum[i][j] = max(maximum[i][j - 1], maximum[i - 1][j]) * grid[i][j];
                    minimum[i][j] = min(minimum[i][j - 1], minimum[i - 1][j]) * grid[i][j];
                } else {
                    maximum[i][j] = min(minimum[i][j - 1], minimum[i - 1][j]) * grid[i][j];
                    minimum[i][j] = max(maximum[i][j - 1], maximum[i - 1][j]) * grid[i][j];
                }
            }
        }

        return maximum[n - 1][m - 1] >= 0 ? maximum[n - 1][m - 1] % MOD : -1;
    }
};

#ifdef _DEBUG
/*
[[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]

之前的逻辑：
ll left_max = j ? maximum[i][j - 1] : 1;
ll left_min = j ? minimum[i][j - 1] : 1;
ll up_max = i ? maximum[i - 1][j] : 1;
ll up_min = i ? minimum[i - 1][j] : 1;
minimum[i][j] = max(left_max, up_max) * grid[i][j];  // when grid[i][j] < 0
错在：
-1 -2
在-2时候，min和max都应该是2，但是max(-1, 1)会导致计算结果为-2。

-1
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.maxProductPath(v) << endl;
    }
    return 0;
}
#endif
