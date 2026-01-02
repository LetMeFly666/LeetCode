/*
 * @Author: LetMeFly
 * @Date: 2026-01-02 12:47:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-02 17:23:19
 */
package main

import "sort"

func repeatedNTimes(nums []int) int {
    sort.Ints(nums)
    for i := 1; i < len(nums); i++ {
        if nums[i] == nums[i - 1] {
            return nums[i]
        }
    }
    return -1  // FAKE RETURN
}