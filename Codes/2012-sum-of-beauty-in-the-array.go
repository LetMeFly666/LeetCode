/*
 * @Author: LetMeFly
 * @Date: 2025-03-11 14:10:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-11 14:13:05
 */
package main

func sumOfBeauties(nums []int) (ans int) {
    mn := make([]int, len(nums))
    now := 100000
    for i := len(nums) - 1; i >= 0; i-- {
        now = min(now, nums[i])
        mn[i] = now
    }
    now = nums[0]
    for i := 1; i < len(nums) - 1; i++ {
        if now < nums[i] && nums[i] < mn[i + 1] {
            ans += 2
        } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
            ans++
        }
        now = max(now, nums[i])
    }
    return
}