/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 10:15:13
 */
package main

func smallestSubarrays(nums []int) []int {
    ans := make([]int, len(nums))
    lastPos := make([]int, 31)
    for i := len(nums) - 1; i >= 0; i-- {
        last := i
        for j := 0; j < 31; j++ {
            if nums[i] >> j & 1 == 1 {
                lastPos[j] = i
            } else {
                last = max(last, lastPos[j])
            }
        }
        ans[i] = max(ans[i], last - i + 1)
    }
    return ans
}