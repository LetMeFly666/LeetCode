/*
 * @Author: LetMeFly
 * @Date: 2025-05-05 21:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-05 22:28:23
 */
class Solution {
    private static int MOD = 1000000007;

    public int numTilings(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((dp[i - 1] * 2) % MOD + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
}