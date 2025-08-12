/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 10:04:08
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// dp[i]: 和为i的方案数
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> pows;
        int now = x;
        while (now <= n) {
            pows.push_back(now);
            now *= x;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int p : pows) {
                if (p > i) {
                    break;
                }
                dp[i] += dp[i - p];
            }
        }
        return dp.back();
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
10 2

1
*/
int main() {
    int a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.numberOfWays(a, b) << endl;
    }
    return 0;
}
#endif