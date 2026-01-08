/*
 * @Author: LetMeFly
 * @Date: 2026-01-08 09:21:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-08 09:45:31
 */
import java.util.Arrays;

class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[][] dp = new int[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1000000);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = Math.max(nums1[i-1] * nums2[j-1], Math.max(dp[i-1][j], Math.max(dp[i][j - 1], dp[i-1][j-1] + nums1[i-1] * nums2[j-1])));
            }
        }
        return dp[n][m];
    }
}