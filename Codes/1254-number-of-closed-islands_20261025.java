/*
 * @Author: LetMeFly
 * @Date: 2026-10-25 09:03:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-10-25 12:56:37
 */
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    private int n, m;
    private final int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private boolean isCenter(int i, int j) {
        return 0 < i && i < n - 1 && 0 < j && j < m - 1;
    }

    private boolean inGrid(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }

    public int closedIsland(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    continue;
                }
                grid[i][j] = 1;
                boolean ok = isCenter(i, j);
                Queue<int[]> q = new LinkedList<>();
                q.offer(new int[]{i, j});
                while (!q.isEmpty()) {
                    int[] top = q.poll();
                    int x = top[0], y = top[1];
                    for (int[] d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (!inGrid(nx, ny) || grid[nx][ny] == 1) {
                            continue;
                        }
                        grid[nx][ny] = 1;
                        ok &= isCenter(nx, ny);
                        q.offer(new int[]{nx, ny});
                    }
                }
                if (ok) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
