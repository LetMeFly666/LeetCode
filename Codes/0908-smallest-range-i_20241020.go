/*
 * @Author: LetMeFly
 * @Date: 2024-10-21 14:37:09
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-21 14:37:16
 */
package main

import "slices"

func smallestRangeI(nums []int, k int) int {
    return max(0, slices.Max(nums) - slices.Min(nums) - 2 * k)
}