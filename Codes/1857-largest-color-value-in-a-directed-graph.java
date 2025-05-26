/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 22:02:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 23:48:54
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        List<Integer>[] out = new ArrayList[colors.length];
        for (int i = 0; i < colors.length; i++) {
            out[i] = new ArrayList<>();
        }
        int[] indegree = new int[colors.length];
        for (int[] edge : edges) {
            out[edge[0]].add(edge[1]);
            indegree[edge[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < colors.length; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        int[][]dp = new int[colors.length][26];
        int ans = 0;
        while (!q.isEmpty()) {
            int thisNode = q.poll();
            ans = Math.max(ans, ++dp[thisNode][colors.charAt(thisNode) - 'a']);
            for (int nextNode : out[thisNode]) {
                indegree[nextNode]++;
                if (indegree[nextNode] == 0) {
                    q.offer(nextNode);
                }
                for (int i = 0; i < 26; i++) {
                    dp[nextNode][i] = Math.max(dp[nextNode][i], dp[thisNode][i]);
                }
            }
        }
        for (int i = 0; i < colors.length; i++) {
            if (indegree[i] != 0) {
                return -1;
            }
        }
        return ans;
    }
}