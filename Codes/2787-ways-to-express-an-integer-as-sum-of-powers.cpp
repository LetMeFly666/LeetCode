/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 18:55:05
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

// dp[i]: 和为i的方案数
class Solution {
private:
    static const long long MOD = 1e9 + 7;

    int pow(int a, int b) {
        long long ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    int numberOfWays(int n, int x) {
        vector<long long> pows;
        for (int i = 1; ; i++) {
            int p = pow(i, x);
            if (p > n) {
                break;
            }
            pows.push_back(p);
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int p : pows) {
            for (int i = n; i >= p; i--) {
                dp[i] = (dp[i] + dp[i - p]) % MOD;
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

/*
4 1


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