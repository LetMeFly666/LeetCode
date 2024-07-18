/*
 * @Author: LetMeFly
 * @Date: 2024-07-18 11:04:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-18 11:20:52
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        List<int[]>[] graph = new ArrayList[n];
        Arrays.setAll(graph, i -> new ArrayList<>());
        for (int[] edge : edges) {
            graph[edge[0]].add(new int[]{edge[1], edge[2]});
            graph[edge[1]].add(new int[]{edge[0], edge[2]});
        }
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        pq.add(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int thisTime = temp[0];
            int thisNode = temp[1];
            if (ans[thisNode] != -1) {
                continue;
            }
            ans[thisNode] = thisTime;
            for (int[] temp2 : graph[thisNode]) {
                int nextNode = temp2[0];
                int length = temp2[1];
                if (ans[nextNode] == -1 && thisTime + length < disappear[nextNode]) {
                    pq.add(new int[]{thisTime + length, nextNode});
                }
            }
        }
        return ans;
    }
}