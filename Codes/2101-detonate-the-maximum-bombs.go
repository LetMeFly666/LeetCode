/*
 * @Author: LetMeFly
 * @Date: 2024-07-23 00:08:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-23 10:18:46
 */
package main

var visited []bool
var graph [][]int

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func dfs(x int) int {
    visited[x] = true
    ans := 1
    for _, nextNode := range graph[x] {
        if !visited[nextNode] {
            ans += dfs(nextNode)
        }
    }
    return ans
}

func maximumDetonation(bombs [][]int) int {
    n := len(bombs)
    graph = make([][]int, n)
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            d2 := (int64)(bombs[i][0] - bombs[j][0]) * (int64)(bombs[i][0] - bombs[j][0]) + (int64)(bombs[i][1] - bombs[j][1]) * (int64)(bombs[i][1] - bombs[j][1])
            if d2 <= (int64)(bombs[i][2]) * (int64)(bombs[i][2]) {
                graph[i] = append(graph[i], j)
            }
            if d2 <= (int64)(bombs[j][2]) * (int64)(bombs[j][2]) {
                graph[j] = append(graph[j], i)
            }
        }
    }

    ans := 1
    for i := 0; i < n; i++ {
        visited = make([]bool, n)
        ans = max(ans, dfs(i))
    }
    return ans
}