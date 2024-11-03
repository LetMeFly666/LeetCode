/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 21:53:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 21:57:54
 */
class Solution {
    private int[] fa;

    private int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    private void union(int x, int y) {
        fa[find(x)] = find(y);
    }

    public int[] findRedundantConnection(int[][] edges) {
        fa = new int[edges.length + 1];
        for (int i = 1; i <= edges.length; i++) {
            fa[i] = i;
        }
        for (int[] edge : edges) {
            if (find(edge[0]) == find(edge[1])) {
                return edge;
            } else {
                union(edge[0], edge[1]);
            }
        }
        return new int[0];
    }
}