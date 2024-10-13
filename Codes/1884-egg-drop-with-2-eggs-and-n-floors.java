import java.util.Arrays;

/*
 * @Author: LetMeFly
 * @Date: 2024-10-13 23:52:52
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-13 23:55:09
 */
class Solution {
    public int twoEggDrop(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 10000);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = Math.min(dp[i], Math.max(j, dp[i - j] + 1));
            }
        }
        return dp[n];
    }
}