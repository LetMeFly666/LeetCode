/*
 * @Author: LetMeFly
 * @Date: 2025-07-23 00:10:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-23 00:13:19
 */
package main

func maximumLength(nums []int, k int) (ans int) {
    for res := 0; res < k; res++ {
        dp := make([]int, k)
        for _, a := range nums {
            a %= k
            dp[a] = dp[(res - a + k) % k] + 1
            ans = max(ans, dp[a])
        }
    }
    return
}