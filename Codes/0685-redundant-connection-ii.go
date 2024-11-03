/*
 * @Author: LetMeFly
 * @Date: 2024-11-03 17:17:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-03 17:34:06
 */
package main

type UnionFind struct {
    fa []int
}

func New(n int) UnionFind {
    fa := make([]int, n + 1)
    for th, _ := range fa {
        fa[th] = th
    }
    return UnionFind{fa}
}

func (unionFind UnionFind) _find(x int) int {
    if unionFind.fa[x] != x {
        unionFind.fa[x] = unionFind._find(unionFind.fa[x])
    }
    return unionFind.fa[x]
}

func (unionFind UnionFind) isUnion(x, y int) bool {
    return unionFind._find(x) == unionFind._find(y)
}

func (unionFind UnionFind) union(x, y int) {
    unionFind.fa[unionFind._find(x)] = unionFind._find(y)
}

func canRemoveThisEdge(edges [][]int, index int) bool {
    unionFind := New(len(edges))
    for i := 0; i < len(edges); i++ {
        if i == index {
            continue
        }
        if unionFind.isUnion(edges[i][0], edges[i][1]) {
            return false
        } else {
            unionFind.union(edges[i][0], edges[i][1])
        }
    }
    return true
}

func solution_indegree(edges [][]int, node int) []int {
    for i := len(edges) - 1; i >= 0; i-- {
        if edges[i][1] == node && canRemoveThisEdge(edges, i) {
            return edges[i]
        }
    }
    return make([]int, 0)  // FAKE RETURN
}

func solution_unionFind(edges [][]int) []int {
    unionFind := New(len(edges))
    for _, edge := range edges {
        if unionFind.isUnion(edge[0], edge[1]) {
            return edge
        } else {
            unionFind.union(edge[0], edge[1])
        }
    }
    return make([]int, 0)  // FAKE RETURN
}

func findRedundantDirectedConnection(edges [][]int) []int {
    hasIndegree := make([]bool, len(edges) + 1)
    for _, edge := range edges {
        if hasIndegree[edge[1]] {
            return solution_indegree(edges, edge[1])
        } else {
            hasIndegree[edge[1]] = true
        }
    }
    return solution_unionFind(edges)
}