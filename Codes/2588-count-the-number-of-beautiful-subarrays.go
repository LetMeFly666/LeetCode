/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 16:46:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 16:46:39
 */
package main

func beautifulSubarrays(nums []int) (ans int64) {
    times := map[int]int{0: 1}
    val := 0
    for _, t := range nums {
        val ^= t
        ans += int64(times[val])
        times[val]++
    }
    return
}