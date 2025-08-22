/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:33:05
 */
class Solution {
    public int minimumArea(int[][] grid) {
        int l = 1000, r = 0, u = 1000, d = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    l = Math.min(l, j);
                    r = Math.max(r, j);
                    u = Math.min(u, i);
                    d = Math.max(d, i);
                }
            }
        }
        return (r - l + 1) * (d - u + 1);
    }
}