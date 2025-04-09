/*
 * @Author: LetMeFly
 * @Date: 2025-04-09 22:16:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-09 22:18:14
 */
package main

import "slices"

func minOperations(nums []int, k int) (ans int) {
    slices.Sort(nums)
    if nums[0] < k {
        return -1
    }
    for i := len(nums) - 1; i > 0; i-- {
        if nums[i] != nums[i - 1] {
            ans++
        }
    }
    if nums[0] != k {
        ans++
    }
    return
}