/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 14:16:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 14:18:33
 */
package main

func longestCycle(edges []int) int {
    ans := -1
    cnt := 1
    visited := make([]int, len(edges))
    for i := range edges {
        begin := cnt
        for edges[i] != -1 && visited[i] == 0 {
            visited[i] = cnt
            cnt++
            i = edges[i]
        }
        if edges[i] != -1 && visited[i] >= begin {
            ans = max(ans, cnt - visited[i])
        }
    }
    return ans
}