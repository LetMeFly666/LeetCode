/*
 * @Author: LetMeFly
 * @Date: 2025-01-16 12:29:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-16 12:31:29
 */
package main

func minimumSubarrayLength(nums []int, k int) int {
    ans := 100
    for l, val := range nums {
        for r := l; r < len(nums); r++ {
            val |= nums[r]
            if val >= k {
                ans = min(ans, r - l + 1)
                break
            }
        }
    }
    if ans == 100 {
        return -1
    }
    return ans
}