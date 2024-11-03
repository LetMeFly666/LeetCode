/*
 * @Author: LetMeFly
 * @Date: 2024-11-02 21:58:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-02 22:03:24
 */
package main

func find(fa []int, x int) int {
    if fa[x] != x {
        fa[x] = find(fa, fa[x])
    }
    return fa[x]
}

func union(fa []int, x int, y int) {
    fa[find(fa, x)] = find(fa, y)
}

func findRedundantConnection(edges [][]int) []int {
    fa := make([]int, len(edges) + 1)
    for th, _ := range fa {
        fa[th] = th
    }
    for _, edge := range edges {
        if find(fa, edge[0]) == find(fa, edge[1]) {
            return edge
        } else {
            union(fa, edge[0], edge[1])
        }
    }
    return nil
}