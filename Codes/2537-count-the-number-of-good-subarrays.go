/*
 * @Author: LetMeFly
 * @Date: 2025-04-16 20:50:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-16 20:56:36
 */
package main

func countGood(nums []int, k int) (ans int64) {
    times := map[int]int64{}
    now := int64(0)
    for l, r := 0, 0; r < len(nums); r++ {
        now += times[nums[r]]
        times[nums[r]]++
        for now >= int64(k) {
            times[nums[l]]--
            now -= times[nums[l]]
            l++
        }
        ans += int64(l)
    }
    return
}