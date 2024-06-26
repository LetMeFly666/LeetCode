/*
 * @Author: LetMeFly
 * @Date: 2024-06-26 16:19:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-26 17:17:47
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif


#ifdef FirstTry  // Error，ans = 0
/*
dp[i][j]: 状态为i，最后一个数字为j

*/
const static long long MOD = 1e9 + 7;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
        }
        long long ans = 0;
        for (int state = 0; state < (1 << n); state++) {
            for (int last = 0; last < n; last++) {  // 最后一位
                for (int prev = 0; prev < n; prev++) {  // 上一位
                    if ((state & (1 << last)) && (state & (1 << prev)) && last != prev && (nums[last] % nums[prev] == 0 || nums[prev] % nums[last] == 0)) {
                        dp[state][last] = (dp[state][last] + dp[state ^ (1 << prev)][prev]) % MOD;
                    }
                }
                if (state == (1 << n) - 1) {
                    ans = (ans + dp[state][last]) % MOD;
                }
            }
        }
        return ans;
    }
};
#else  // FirstTry
// SecondTry
const static long long MOD = 1e9 + 7;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
        }
        for (int state = 0; state < (1 << n); state++) {
            for (int prev = 0; prev < n; prev++) {  // 上一位
                for (int last = 0; last < n; last++) {  // 最后一位
                    if ((state & (1 << last)) && (state & (1 << prev)) && last != prev && (nums[last] % nums[prev] == 0 || nums[prev] % nums[last] == 0)) {
                        dp[state][last] = (dp[state][last] + dp[state ^ (1 << last)][prev]) % MOD;
                    }
                }
            }
        }
        long long ans = 0;
        for (int last = 0; last < n; last++) {
            ans = (ans + dp[(1 << n) - 1][last]) % MOD;
        }
        return ans;
    }
};
#endif  // FirstTry

#ifdef _WIN32
int main() {
    vector<int> a = {2, 3, 6};
    Solution sol;
    dbg(sol.specialPerm(a));
    return 0;
}
#endif