/*
 * @Author: LetMeFly
 * @Date: 2024-11-03 17:02:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-03 17:15:28
 */
class UnionFind {
    private int[] fa;

    public UnionFind(int n) {
        fa = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }

    private int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    public boolean isUnion(int x, int y) {
        return find(x) == find(y);
    }

    public void union(int x, int y) {
        fa[find(x)] = find(y);
    }
}

class Solution {
    private boolean canRemoveThisEdge(int[][] edges, int index) {
        UnionFind unionFind = new UnionFind(edges.length);
        for (int i = 0; i < edges.length; i++) {
            if (i == index) {
                continue;
            }
            if (unionFind.isUnion(edges[i][0], edges[i][1])) {
                return false;
            } else {
                unionFind.union(edges[i][0], edges[i][1]);
            }
        }
        return true;
    }

    private int[] solution_indegree(int[][] edges, int node) {
        for (int i = edges.length - 1; i >= 0; i--) {
            if (edges[i][1] == node && canRemoveThisEdge(edges, i)) {
                return edges[i];
            }
        }
        return new int[0];  // FAKE RETURN
    }

    private int[] solution_unionFind(int[][] edges) {
        UnionFind unionFind = new UnionFind(edges.length);
        for (int[] edge : edges) {
            if (unionFind.isUnion(edge[0], edge[1])) {
                return edge;
            } else {
                unionFind.union(edge[0], edge[1]);
            }
        }
        return new int[0];  // FAKE RETURN
    }
    
    public int[] findRedundantDirectedConnection(int[][] edges) {
        boolean[] hasIndegree = new boolean[edges.length + 1];
        for (int[] edge : edges) {
            if (hasIndegree[edge[1]]) {
                return solution_indegree(edges, edge[1]);
            } else {
                hasIndegree[edge[1]] = true;
            }
        }
        return solution_unionFind(edges);
    }
}