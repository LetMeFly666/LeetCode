/*
 * @Author: LetMeFly
 * @Date: 2025-05-09 12:45:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-09 13:45:08
 */
import java.util.PriorityQueue;
import java.util.Arrays;

class Solution {
    private static final int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length, m = moveTime[0].length;
        int[][] ans = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(ans[i], 2000000001);
        }
        ans[0][0] = 0;
        PirorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});
        while (!pq.empty()) {
            int[] node = pq.poll();
            int t = node[0], x = node[1], y = node[2];
            if (t > ans[x][y]) {
                continue;
            }
            for (int[] d : directions) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int nt = Math.max(t, moveTime[nx][ny]) + (x + y) % 2 + 1;
                if (nt < moveTime[nx][ny]) {
                    moveTime[nx][ny] = nt;
                    pq.offer(new int[]{nt, nx, ny});
                }
            }
        }
        return ans[n - 1][m - 1];
    }
}