/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 17:31:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:31:49
 */
package main

import "sort"

func repeatedNTimes(nums []int) int {
    sort.Ints(nums)
    for i := 2; i < len(nums); i++ {
        if nums[i] == nums[i-1] || nums[i] == nums[i-2] {
            return nums[i]
        }
    }
    return nums[0]
}