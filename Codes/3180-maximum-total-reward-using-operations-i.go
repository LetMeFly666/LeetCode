/*
 * @Author: LetMeFly
 * @Date: 2024-10-28 21:29:02
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-28 21:38:12
 */
package main

import "sort"

func maxTotalReward(rewardValues []int) int {
    sort.Ints(rewardValues)
    dp := make([]bool, 2 * rewardValues[len(rewardValues) - 1])
    dp[0] = true
    for _, x := range rewardValues {
        for i := x; i < 2 * x; i++ {
            // dp[i] = dp[i] | dp[i - x]
            // var a, b bool = true, false
            // a |= b
            // a = a | b
            if dp[i - x] {
                dp[i] = true
            }
        }
    }
    ans := len(dp) - 1
    for !dp[ans] {
        ans--
    }
    return ans
}