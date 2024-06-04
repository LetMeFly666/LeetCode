/*
 * @Author: LetMeFly
 * @Date: 2024-06-04 21:55:34
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-06-04 22:16:45
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        // init
        List<int[]>[] graph = new ArrayList[edges.length + 1];
        Arrays.setAll(graph, i -> new ArrayList<int[]>());
        for (int[] edge : edges) {
            graph[edge[0]].add(new int[]{edge[1], edge[2]});
            // HALF  // 11点去洗澡，待会儿再背点单词，写不完了，先不写Java版本了。
        }
    }
}