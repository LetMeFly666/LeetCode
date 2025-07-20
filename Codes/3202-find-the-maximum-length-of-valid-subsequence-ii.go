/*
 * @Author: LetMeFly
 * @Date: 2025-07-18 22:33:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-20 22:28:07
 */
package main

func maximumLength(nums []int, k int) (ans int) {
    dp := make([][]int, k)
    for i := range dp {
        dp[i] = make([]int, k)
    }
    for _, x := range nums {
        x %= k
        for y := range dp {
            dp[y][x] = dp[x][y] + 1
            ans = max(ans, dp[y][x])
        }
    }
    return
}