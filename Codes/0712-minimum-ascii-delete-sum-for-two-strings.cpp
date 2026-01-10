/*
 * @Author: LetMeFly
 * @Date: 2026-01-10 09:12:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-10 09:24:25
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int minimumDeleteSum(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i - 1]);
                }
            }
        }
        int total = 0;
        for (char c : s1) {
            total += c;
        }
        for (char c : s2) {
            total += c;
        }
        return total - 2 * dp[n][m];
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
sea eat

231
*/
int main() {
    string a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.minimumDeleteSum(a, b) << endl;
    }
    return 0;
}
#endif