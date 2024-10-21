/*
 * @Author: LetMeFly
 * @Date: 2024-10-21 23:11:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-10-21 23:13:07
 */
package main

import "slices"

func smallestRangeII(nums []int, k int) int {
    slices.Sort(nums)
    ans := nums[len(nums) - 1] - nums[0]
    for i := 0; i < len(nums) - 1; i++ {
        ans = min(ans, max(nums[i] + k, nums[len(nums) - 1] - k) - min(nums[i + 1] - k, nums[0] + k))
    }
    return ans
}