/*
 * @Author: LetMeFly
 * @Date: 2025-05-05 21:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-05 22:38:29
 */
package main

var MOD int = 1000000007

func numTilings(n int) int {
    if n == 1 {
        return 1
    }
    dp := make([]int, n + 1)
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    for i := 3; i <= n; i++ {
        dp[i] = (dp[i - 1] * 2 % MOD + dp[i - 3]) % MOD
    }
    return dp[n]
}