/*
 * @Author: LetMeFly
 * @Date: 2025-08-17 19:33:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-17 22:20:30
 */
package main

func new21Game(n int, k int, maxPts int) float64 {
    dp := make([]float64, k + maxPts)
    s := 0.
    for i := k; i < k + maxPts; i++ {
        if i <= n {
            dp[i] = 1.
        } else {
            dp[i] = 0.
        }
        s += dp[i]  // 别忘了
    }
    for i := k - 1; i >= 0; i-- {
        dp[i] = s / float64(maxPts)
        s = s + dp[i] - dp[i + maxPts]
    }
    return dp[0]
}