/*
 * @Author: LetMeFly
 * @Date: 2025-10-15 22:07:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-15 22:25:04
 */
package main

// 我发现nowCnt特别容易打成nowCNt
func maxIncreasingSubarrays(nums []int) int {
    ans, lastCnt, nowCnt := 0, 0, 0
    for i, t := range nums {
        nowCnt++
        if i == len(nums) - 1 || t >= nums[i + 1] {
            ans = max(ans, max(min(lastCnt, nowCnt), nowCnt / 2))
            lastCnt, nowCnt = nowCnt, 0
        }
    }
    return ans
}