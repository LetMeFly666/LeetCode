/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 21:39:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 22:27:50
 */
package main

func countHillValley(nums []int) (ans int) {
    last := nums[0]
    for i := 1; i < len(nums) - 1; i++ {
        if nums[i] > last && nums[i] > nums[i + 1] || nums[i] < last && nums[i] < nums[i + 1] {
            ans++
        }
        if nums[i] != nums[i + 1] {
            last = nums[i]
        }
    }
    return
}