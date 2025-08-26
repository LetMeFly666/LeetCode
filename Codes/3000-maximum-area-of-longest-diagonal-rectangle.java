/*
 * @Author: LetMeFly
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:36:58
 */
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0;
        int M = 0;
        for (int[] d : dimensions) {
            int l2 = d[0] * d[0] + d[1] * d[1];
            if (l2 > M) {
                M = l2;
                ans = d[0] * d[1];
            } else if (l2 == M) {
                ans = Math.max(ans, d[0] * d[1]);
            }
        }
        return ans;
    }
}