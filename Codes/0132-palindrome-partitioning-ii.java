/*
 * @Author: LetMeFly
 * @Date: 2025-03-02 12:34:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-02 12:38:17
 */
class Solution {
    public int minCut(String s) {
        boolean[][] isOk = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                isOk[i][j] = true;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                isOk[i][j] = s.charAt(i) == s.charAt(j) && isOk[i + 1][j - 1];
            }
        }

        int[] dp = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i] = 100000;
        }
        for (int i = 0; i < s.length(); i++) {
            if (isOk[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isOk[j + 1][i]) {
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[dp.length - 1];
    }
}