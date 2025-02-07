/*
 * @Author: LetMeFly
 * @Date: 2025-02-07 20:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-07 20:52:38
 */
class Solution {
    private int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int d = 0, x = 0, y = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx == n || nx < 0 || ny == n || ny < 0 || ans[nx][ny] > 0) {
                d = (d + 1) % 4;
                nx = x + directions[d][0];
                ny = y + directions[d][1];
            }
            x = nx;
            y = ny;
        }
        return ans;
    }
}