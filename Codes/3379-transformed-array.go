/*
 * @Author: LetMeFly
 * @Date: 2026-02-15 18:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-15 18:15:07
 */
package main

func constructTransformedArray(nums []int) []int {
    ans := make([]int, len(nums))
    n := len(nums)
    for i, v := range nums {
        ans[i] = nums[((v + i) % n + n) % n]
    }
    return ans
}