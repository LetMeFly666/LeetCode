/*
 * @Author: LetMeFly
 * @Date: 2022-11-21 21:09:26
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-21 21:34:41
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000)
            return 1;
        n = n / 25 + (n % 25 != 0);
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
        for (int j = 1; j <= n; j++) {
            dp[0][j] = 1;
        }
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 0.25 * (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] + dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]);
            }
        }
        return dp[n][n];
    }
};

#ifdef _WIN32
int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.soupServings(n) << endl;
    }
    return 0;
}
#endif