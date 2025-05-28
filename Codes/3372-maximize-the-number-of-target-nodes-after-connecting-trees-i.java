/*
 * @Author: LetMeFly
 * @Date: 2025-05-28 21:43:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-28 23:18:09
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    private int[][] buildTree(int[][] edges) {
        List<Integer>[] ans = new ArrayList<>()[edges.length + 1];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            ans[edge[0]].add(edge[1]);
            ans[edge[1]].add(edge[0]);
        }
        return ans;
    }

    private int dfs(List<Integer>[] tree, int lastNode, int thisNode, int k) {
        if (k < 0) {
            return 0;
        }
        int ans = 1;
        for (int nextNode : tree[thisNode]) {
            if (nextNode != lastNode) {
                ans += dfs(tree, thisNode, nextNode, k - 1);
            }
        }
        return ans;
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        List<Integer>[] tree2 = buildTree(edges2);
        int add = 0;
        for (int i = 0; i < tree2.length; i++) {
            add = Math.max(add, dfs(tree2, -1, i, k - 1));
        }
        List<Integer>[] tree1 = buildTree(edges1);
        int[] ans = new int[tree1.length];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = add + dfs(tree1, -1, i, k);
        }
        return ans;
    }
}