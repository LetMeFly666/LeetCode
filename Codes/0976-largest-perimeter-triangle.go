/*
 * @Author: LetMeFly
 * @Date: 2025-09-28 13:21:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-28 13:29:34
 */
package main

import "sort"

func largestPerimeter(nums []int) int {
    sort.Ints(nums)
    for i := len(nums) - 3; i >= 0; i-- {
        if nums[i] + nums[i + 1] > nums[i + 2] {
            return nums[i] + nums[i + 1] + nums[i + 2]
        }
    }
    return 0
}