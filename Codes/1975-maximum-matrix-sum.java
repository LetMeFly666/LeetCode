/*
 * @Author: LetMeFly
 * @Date: 2026-01-05 13:31:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-05 18:43:31
 */
class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long ans = 0;
        int cnt = 0, min = 1000000;
        for (int[] row : matrix) {
            for (int t : row) {
                if (t < 0) {
                    cnt++;
                }
                t = Math.abs(t);
                ans += t;
                min = Math.min(min, t);
            }
        }
        if (cnt % 2 == 1) {
            ans -= 2 * min;
        }
        return ans;
    }
}