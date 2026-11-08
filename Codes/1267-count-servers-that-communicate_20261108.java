/*
 * @Author: LetMeFly
 * @Date: 2026-11-08 10:46:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-11-08 10:54:31
 */
class Solution {
    public int countServers(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[] a = new int[n];
        int[] b = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    a[i]++;
                    b[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (a[i] > 1 || b[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
