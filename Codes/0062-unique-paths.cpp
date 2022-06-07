/*
 * @Author: LetMeFly
 * @Date: 2022-06-07 08:33:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-07 08:55:49
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#else
typedef long long ll;
#endif

#ifdef FirstTry  // 方法一：动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
#else  // FirstTry
// 方法二：排列组合
/*
*                              (m + n - 2)(m + n - 3)···n
*     C(n + m - 2, m - 1)  =   --------------------------
*                                       (m - 1)!
*
*     (m + n - 2) - n + 1 = m - 1
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        ll ans = 1;
        for (int x = n, y = 1; y < m; x++, y++) {
            ans = ans * x / y;
        }
        return ans;
    }
};
#endif  // FirstTry