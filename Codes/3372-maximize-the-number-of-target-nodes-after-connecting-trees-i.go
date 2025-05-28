/*
 * @Author: LetMeFly
 * @Date: 2025-05-28 21:43:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-29 00:43:41
 */
package main

func buildTree3372(edges [][]int) [][]int {
    ans := make([][]int, len(edges) + 1)
    for _, edge := range edges {
        ans[edge[0]] = append(ans[edge[0]], edge[1])
        ans[edge[1]] = append(ans[edge[1]], edge[0])
    }
    return ans
}

func dfs3372(tree [][]int, lastNode, thisNode, k int) int {
    if k < 0 {
        return 0
    }
    ans := 1
    for _, nextNode := range tree[thisNode] {
        if nextNode != lastNode {
            ans += dfs3372(tree, thisNode, nextNode, k - 1)
        }
    }
    return ans
}

func maxTargetNodes(edges1 [][]int, edges2 [][]int, k int) []int {
    tree2 := buildTree3372(edges2)
    toAdd := 0
    for i := range tree2 {
        toAdd = max(toAdd, dfs3372(tree2, -1, i, k - 1))
    }
    tree1 := buildTree3372(edges1)
    ans := make([]int, len(tree1))
    for i := range ans {
        ans[i] = toAdd + dfs3372(tree1, -1, i, k)
    }
    return ans
}