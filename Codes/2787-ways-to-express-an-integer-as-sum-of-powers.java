/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 21:50:02
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int numberOfWays(int n, int x) {
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for (int th = 1; ; th++) {
            int p = (int)Math.pow(th, x);
            if (p > n) {
                break;
            }
            for (int i = n; i >= p; i--) {
                dp[i] += dp[i - p];
            }
        }
        return (int)(dp[n] % 1000000007);
    }
}