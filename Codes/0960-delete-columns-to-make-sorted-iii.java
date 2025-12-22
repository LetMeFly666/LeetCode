/*
 * @Author: LetMeFly
 * @Date: 2025-12-22 22:28:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-22 22:59:50
 */
class Solution {
    private boolean can(String[] strs, int prev, int cur) {
        for (String s : strs) {
            if (s.charAt(prev) > s.charAt(cur)) {
                return false;
            }
        }
        return true;
    }

    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        int[] dp = new int[m];
        int longest = 0;
        for (int cur = 0; cur < m; cur++) {
            for (int prev = 0; prev < cur; prev++) {
                if (dp[cur] < dp[prev] && can(strs, prev, cur)) {
                    dp[cur] = dp[prev];
                }
            }
            longest = Math.max(longest, ++dp[cur]);
        }
        return m - longest;
    }
}