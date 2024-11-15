/*
 * @Author: LetMeFly
 * @Date: 2024-11-15 09:43:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-15 12:50:05
 */
class Solution {
    private int forLine(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                if (grid[i][j] != grid[i][m - j - 1]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    private int forCol(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][j] != grid[n - i - 1][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }

    public int minFlips(int[][] grid) {
        return Math.min(forLine(grid), forCol(grid));
    }
}