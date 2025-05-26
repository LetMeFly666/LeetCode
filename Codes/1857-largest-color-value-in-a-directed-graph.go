/*
 * @Author: LetMeFly
 * @Date: 2025-05-26 22:02:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-26 23:59:12
 */
package main

func largestPathValue(colors string, edges [][]int) (ans int) {
    out := make([][]int, len(colors))
    for i := range out {
        out[i] = make([]int, 0)
    }
    indegree := make([]int, len(colors))
    for _, edge := range edges {
        out[edge[0]] = append(out[edge[0]], edge[1])
        indegree[edge[1]]++
    }
    q := []int{}
    for i, v := range indegree {
        if v == 0 {
            q = append(q, i)
        }
    }
    dp := make([][]int, len(colors))
    for i := range dp {
        dp[i] = make([]int, 26)
    }
    for len(q) > 0 {
        thisNode := q[len(q) - 1]
        q = q[:len(q) - 1]
        dp[thisNode][colors[thisNode] - 'a']++
        ans = max(ans, dp[thisNode][colors[thisNode] - 'a'])
        for _, nextNode := range out[thisNode] {
            indegree[nextNode]--
            if indegree[nextNode] == 0 {
                q = append(q, nextNode)
            }
            for i := 0; i < 26; i++ {
                dp[nextNode][i] = max(dp[nextNode][i], dp[thisNode][i])
            }
        }
    }
    for _, v := range indegree {
        if v != 0 {
            return -1
        }
    }
    return
}