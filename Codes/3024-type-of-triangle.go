/*
 * @Author: LetMeFly
 * @Date: 2025-05-19 13:22:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-19 13:35:48
 */
package main

import "sort"

func triangleType(nums []int) string {
    sort.Ints(nums)
    if nums[0] + nums[1] <= nums[2] {
        return "none"
    }
    if nums[0] == nums[1] && nums[1] == nums[2] {
        return "equilateral"
    }
    if nums[0] == nums[1] || nums[1] == nums[2] {
        return "isosceles"
    }
    return "scalene"
}