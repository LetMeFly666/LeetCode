/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 13:45:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 13:51:57
 */
class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] minop = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                minop[i][j] = minop[i + 1][j - 1];
                if (s.charAt(i) != s.charAt(j)) {
                    minop[i][j]++;
                }
            }
        }
        int[][] dp = new int[n][k];
        for (int i = 0; i < n; i++) {
            dp[i][0] = minop[0][i];
            for (int j = 1; j < k; j++) {
                dp[i][j] = 1000;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < Math.min(k, i + 1); j++) {
                for (int i0 = 0; i0 < i; i0++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i]);
                }
            }
        }
        return dp[n - 1][k - 1];
    }
}