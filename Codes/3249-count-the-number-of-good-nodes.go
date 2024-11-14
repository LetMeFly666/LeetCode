/*
 * @Author: LetMeFly
 * @Date: 2024-11-14 13:15:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-14 13:24:43
 */
package main

// import "fmt"

func countGoodNodes(edges [][]int) (ans int) {
    graph := make([][]int, len(edges) + 1)
    for _, edge := range edges {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        graph[edge[1]] = append(graph[edge[1]], edge[0])
    }
    var dfs func(int, int) int
    dfs = func(thisNode, lastNode int) int {
        // fmt.Println(thisNode, lastNode)
        cnt, oneChild, ok := 1, 0, true
        for _, nextNode := range graph[thisNode] {
            if nextNode == lastNode {
                continue
            }
            thisChild := dfs(nextNode, thisNode)
            cnt += thisChild
            if oneChild == 0 {
                oneChild = thisChild
            } else if oneChild != thisChild {
                ok = false
            }
        }
        if ok {
            ans++
        }
        return cnt
    }
    dfs(0, -1)
    return ans
}