/*
 * @Author: LetMeFly
 * @Date: 2025-10-06 12:17:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-06 14:04:24
 */
import java.util.PriorityQueue;

class Solution {
    private static final int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public int swimInWater(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        if (n == 1 && m == 1) {
            return grid[0][0];
        }
        boolean[][] visited = new boolean[n][m];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> grid[a[0]][a[1]] - grid[b[0]][b[1]]);
        pq.add(new int[]{0, 0});
        visited[0][0] = true;
        while (true) {
            int[] top = pq.poll();
            int x = top[0], y = top[1];
            for (int[] d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                    continue;
                }
                grid[nx][ny] = Math.max(grid[nx][ny], grid[x][y]);
                if (nx == n - 1 && ny == m - 1) {
                    return grid[nx][ny];
                }
                visited[nx][ny] = true;
                pq.add(new int[]{nx, ny});
            }
        }
    }
}