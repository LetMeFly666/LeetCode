/*
 * @Author: LetMeFly
 * @Date: 2025-05-06 21:30:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-06 21:39:38
 */
package main

func buildArray(nums []int) []int {
    ans := make([]int, len(nums))
    for i := range nums {
        ans[i] = nums[nums[i]]
    }
    return ans
}