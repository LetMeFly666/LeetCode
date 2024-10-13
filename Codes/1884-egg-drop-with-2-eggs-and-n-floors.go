/*
 * @Author: LetMeFly
 * @Date: 2024-10-13 23:55:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-13 23:57:38
 */
package main

func twoEggDrop(n int) int {
    dp := make([]int, n + 1)
    for i := range(dp) {
        dp[i] = 10000
    }
    dp[0] = 0
    for i := 1; i <= n; i++ {
        for j := 1; j <= i; j++ {
            dp[i] = min(dp[i], max(j, dp[i - j] + 1))
        }
    }
    return dp[n]
}