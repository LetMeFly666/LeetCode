/*
 * @Author: LetMeFly
 * @Date: 2025-06-25 22:24:22
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-25 22:43:42
 */
package main

func findKDistantIndices(nums []int, key int, k int) (ans []int) {
    for i, j := 0, 0; i < len(nums); i++ {
        if nums[i] == key {
            for j = max(j, i - k); j <= min(len(nums) - 1, i + k); j++ {
                ans = append(ans, j)
            }
        }
    }
    return
}