/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:24:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:24:44
 */
package main

import "sort"

func repeatedNTimes(nums []int) int {
    sort.Ints(nums)
    mid := len(nums) / 2
    if nums[mid] == nums[mid + 1] {
        return nums[mid]
    }
    return nums[mid - 1]
}