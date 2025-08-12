/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 21:42:16
 */
package main

import "math"

func pow2787(a, b int) int {
    return int(math.Pow(float64(a), float64(b)))
}

func numberOfWays(n int, x int) int {
    dp := make([]int, n + 1)
    dp[0] = 1
    for th := 1; ; th++ {
        p := pow2787(th, x)
        if p > n {
            break
        }
        for i := n; i >= p; i-- {
            dp[i] += dp[i - p]
        }
    }
    return dp[n]
}