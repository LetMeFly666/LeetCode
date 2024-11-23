/*
 * @Author: LetMeFly
 * @Date: 2024-11-23 10:17:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-23 10:18:25
 */
class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int cnt[][] = new int[n][11];
        for (int[] p : pick) {
            cnt[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                if (cnt[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}