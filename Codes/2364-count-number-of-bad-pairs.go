/*
 * @Author: LetMeFly
 * @Date: 2025-04-18 10:35:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-18 10:38:47
 */
package main

func countBadPairs(nums []int) int64 {
    ans := len(nums) * (len(nums) - 1) / 2
    times := map[int]int{}
    for i, v := range nums {
        ans -= times[v - i]
        times[v - i]++
    }
    return int64(ans)
}