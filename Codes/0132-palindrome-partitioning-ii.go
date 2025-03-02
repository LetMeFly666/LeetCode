/*
 * @Author: LetMeFly
 * @Date: 2025-03-02 12:39:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-02 12:43:12
 */
package main

func minCut(s string) int {
    isOk := make([][]bool, len(s))
    for i, _ := range isOk {
        isOk[i] = make([]bool, len(s))
        for j, _ := range isOk[i] {
            isOk[i][j] = true
        }
    }
    for i := len(s) - 1; i >= 0; i-- {
        for j := i + 1; j < len(s); j++ {
            isOk[i][j] = s[i] == s[j] && isOk[i + 1][j - 1]
        }
    }

    dp := make([]int, len(s))
    for i, _ := range dp {
        dp[i] = 100000
    }
    for i := 0; i < len(dp); i++ {
        if isOk[0][i] {
            dp[i] = 0
            continue
        }
        for j := 0; j < i; j++ {
            if isOk[j + 1][i] {
                dp[i] = min(dp[i], dp[j] + 1)
            }
        }
    }
    return dp[len(dp) - 1]
}