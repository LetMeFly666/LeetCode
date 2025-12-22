/*
 * @Author: LetMeFly
 * @Date: 2025-12-22 22:28:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-12-22 22:53:21
 */
package main

import "slices"

func can960(strs []string, prev, cur int) bool {
    for _, s := range strs {
        if s[prev] > s[cur] {
            return false
        }
    }
    return true
}

func minDeletionSize(strs []string) int {
    m := len(strs[0])
    dp := make([]int, m)
    for cur := 0; cur < m; cur++ {
        for prev := 0; prev < cur; prev++ {
            if dp[cur] < dp[prev] && can960(strs, prev, cur) {
                dp[cur] = dp[prev]
            }
        }
        dp[cur]++
    }
    return m - slices.Max(dp)
}