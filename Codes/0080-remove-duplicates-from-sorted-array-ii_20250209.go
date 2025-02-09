/*
 * @Author: LetMeFly
 * @Date: 2025-02-09 08:53:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-09 09:00:09
 */
package main

func removeDuplicates(nums []int) int {
    slow := 1
    for fast := 2; fast < len(nums); fast++ {
        if nums[fast] != nums[slow - 1] {
            slow++
            nums[slow] = nums[fast]
        }
    }
    return min(slow + 1, len(nums))
}