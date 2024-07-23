/*
 * @Author: LetMeFly
 * @Date: 2024-07-23 00:00:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-23 00:06:55
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private boolean[] visited;
    private List<Integer>[] graph;

    private int dfs(int x) {
        visited[x] = true;
        int ans = 1;
        for (int nextNode : graph[x]) {
            if (!visited[nextNode]) {
                ans += dfs(nextNode);
            }
        }
        return ans;
    }
    
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        graph = new ArrayList[n];
        Arrays.setAll(graph, thisArray -> new ArrayList<>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long d2 = (long)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (long)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (d2 <= (long)bombs[i][2] * bombs[i][2]) {
                    graph[i].add(j);
                }
                if (d2 <= (long)bombs[j][2] * bombs[j][2]) {
                    graph[j].add(i);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            visited = new boolean[n];
            ans = Math.max(ans, dfs(i));
        }
        return ans;
    }
}