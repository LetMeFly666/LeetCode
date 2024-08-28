/*
 * @Author: LetMeFly
 * @Date: 2024-08-28 23:28:27
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-08-28 23:41:54
 */
package main

func min(a int, b int) int {
    if (a > b) {
        return b
    }
    return a
}

func max(a int, b int) int {
    if (a < b) {
        return b
    }
    return a
}

func minimumSubstringsInPartition(s string) int {
    dp := make([]int, len(s) + 1)
    for i := range dp {
        dp[i] = 100000
    }
    dp[0] = 0
    for i := range s {
        ma := map[byte]int{}
        types, maxTimes := 0, 0
        for j := i; j >= 0; j-- {
            ma[s[j]]++
            maxTimes = max(maxTimes, ma[s[j]])
            if ma[s[j]] == 1 {
                types++
            }
            if types * maxTimes == i - j + 1 {
                dp[i + 1] = min(dp[i + 1], dp[j] + 1)
            }
        }
    }
    return dp[len(s)]
}

