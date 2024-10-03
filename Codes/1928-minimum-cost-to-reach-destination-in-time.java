/*
* @Author: LetMeFly
* @Date: 2024-10-03 12:57:04
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-03 13:03:05
*/

import java.util.Arrays;
class Solution {
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int[][] dp = new int[maxTime + 1][passingFees.length];
        for (int i = 0; i <= maxTime; i++) {
            Arrays.fill(dp[i], 10000000);
        }
        dp[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (int[] edge : edges) {
                int i = edge[0], j = edge[1], cost = edge[2];
                if (cost <= t) {
                    dp[t][j] = Math.min(dp[t][j], dp[t - cost][i] + passingFees[j]);
                    dp[t][i] = Math.min(dp[t][i], dp[t - cost][j] + passingFees[i]);
                }
            }
        }
        int ans = 10000000;
        for (int[] d : dp) {
            ans = Math.min(ans, d[passingFees.length - 1]);
        }
        return ans == 10000000 ? -1 : ans;
    }
}