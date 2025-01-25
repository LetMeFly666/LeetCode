/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 10:05:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 10:06:21
 */
class Solution {
    public long minimumMoney(int[][] transactions) {
        long ans = 0;
        int M = 0;
        for (int[] t : transactions) {
            ans += Math.max(0, t[0] - t[1]);
            M = Math.max(M, Math.min(t[0], t[1]));
        }
        return ans + M;
    }
}