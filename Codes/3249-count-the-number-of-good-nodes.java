/*
 * @Author: LetMeFly
 * @Date: 2024-11-14 13:00:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-14 13:14:26
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private List<Integer>[] graph;
    private int ans;

    private int dfs(int thisNode, int lastNode) {
        int cnt = 1;
        int oneChild = 0;
        boolean ok = true;
        for (int nextChilld : graph[thisNode]) {
            if (nextChilld == lastNode) {
                continue;
            }
            int thisChild = dfs(nextChilld, thisNode);
            cnt += thisChild;
            if (oneChild == 0) {
                oneChild = thisChild;
            } else if (oneChild != thisChild) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
        return cnt;
    }

    public int countGoodNodes(int[][] edges) {
        ans = 0;
        graph = new ArrayList[edges.length + 1];
        Arrays.setAll(graph, i -> new ArrayList<>());
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        dfs(0, -1);
        return ans;
    }
}