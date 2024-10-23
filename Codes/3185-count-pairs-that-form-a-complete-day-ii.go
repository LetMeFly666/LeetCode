/*
 * @Author: LetMeFly
 * @Date: 2024-10-23 22:57:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-23 23:00:15
 */
package main

func countCompleteDayPairs(hours []int) int64 {
    bin := make([]int64, 24)
    var ans int64
    for _, t := range hours {
        ans += bin[(24 - t % 24) % 24]
        bin[t % 24]++
    }
    return ans
}