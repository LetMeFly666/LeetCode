/*
 * @Author: LetMeFly
 * @Date: 2024-11-10 16:45:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-10 17:41:04
 */
package main

func singleNonDuplicate(nums []int) int {
    l, r := 0, len(nums) - 1
    for l < r {
        mid := (l + r) >> 1
        if nums[mid] == nums[mid + 1] {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return nums[l]
}