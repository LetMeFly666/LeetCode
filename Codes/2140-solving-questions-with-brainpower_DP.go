/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:53:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:56:32
 */
package main

func mostPoints(questions [][]int) int64 {
    n := len(questions)
    dp := make([]int64, n + 1)
    for i := n - 1; i >= 0; i-- {
        j := min(i + questions[i][1] + 1, n)
        dp[i] = max(dp[i + 1], dp[j] + int64(questions[i][0]))
    }
    return dp[0]
}