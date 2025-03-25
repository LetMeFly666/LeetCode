/*
 * @Author: LetMeFly
 * @Date: 2025-03-25 21:23:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-25 21:26:25
 */
class Solution {
    public int[][] differenceOfDistinctValues(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] ans = new int[n][m];
        for (int k = 0; k < m + n - 1; k++) {
            int i = k < m ? 0 : m - k + 1;
            int j = k < m ? m : 0;
            long se = 0;
            int d = 0;
            for (; i + d < n && j + d < m; d++) {
                ans[i + d][j + d] = Long.bitCount(se);
                se |= 1L << grid[i + d][j + d];
            }
            se = 0;
            for (d--; d >= 0; d--) {
                ans[i + d][j + d] = Math.abs(ans[i + d][j + d] - Long.bitCount(se));
                se |= 1L << grid[i + d][j + d];
            }
        }
        return ans;
    }
}