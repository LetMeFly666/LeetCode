/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 14:10:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 14:15:56
 */
class Solution {
    public int longestCycle(int[] edges) {
        int ans = -1;
        int cnt = 1;
        int[] visited = new int[edges.length];
        for (int i = 0; i < edges.length; i++) {
            int begin = cnt;
            int x = i;
            while (edges[x] != -1 && visited[x] == 0) {
                visited[x] = cnt++;
                x = edges[x];
            }
            if (edges[x] != -1 && visited[x] >= begin) {
                ans = Math.max(ans, cnt - visited[x]);
            }
        }
        return ans;
    }
}