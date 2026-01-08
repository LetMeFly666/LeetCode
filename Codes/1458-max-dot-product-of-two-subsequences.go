/*
 * @Author: LetMeFly
 * @Date: 2026-01-08 09:21:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-08 09:36:59
 */
package main

func max1458_2(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func max1458(a, b, c, d int) int {
    return max1458_2(a, max1458_2(b, max1458_2(c, d)))
}

func maxDotProduct(nums1 []int, nums2 []int) int {
    n, m := len(nums1), len(nums2)
    dp := make([][]int, n + 1)
    for i := range dp {
        dp[i] = make([]int, m + 1)
        for j := range dp[i] {
            dp[i][j] = -1000000;
        }
    }
    
    for i, x := range nums1 {
        for j, y := range nums2 {
            dp[i+1][j+1] = max1458(x*y, dp[i][j+1], dp[i+1][j], dp[i][j] + x*y)
        }
    }
    return dp[n][m]  // 不是dp[n-1][m-1]
}