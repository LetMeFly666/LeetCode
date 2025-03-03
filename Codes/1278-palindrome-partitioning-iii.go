/*
 * @Author: LetMeFly
 * @Date: 2025-03-03 13:40:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-03 13:48:33
 */
package main

func palindromePartition(s string, k int) int {
    n := len(s)
    minop := make([][]int, n)
    for i, _ := range minop {
        minop[i] = make([]int, n)
    }
    for i := n - 1; i >= 0; i-- {
        for j := i + 1; j < n; j++ {
            minop[i][j] = minop[i + 1][j - 1]
            if s[i] != s[j] {
                minop[i][j]++
            }
        }
    }
    dp := make([][]int, n)
    for i, _ := range dp {
        dp[i] = make([]int, k)
        for j, _ := range dp[i] {
            dp[i][j] = 1000
        }
    }
    for i, _ := range dp {
        dp[i][0] = minop[0][i]
    }
    for i := 1; i < n; i++ {
        for j := 1; j < min(k, i + 1); j++ {
            for i0 := 0; i0 < i; i0++ {
                dp[i][j] = min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i])
            }
        }
    }
    return dp[n - 1][k - 1]
}